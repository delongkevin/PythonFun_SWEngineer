/* Copyright (c) 2020, Texas Instruments Incorporated
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

/*
 * FILE: jacinto7_ddrss_tools_main.c
 */

// Define UART_INSTANCE as 0 - 9
#define UART_INSTANCE 0
#define DDRTOOLS_VERSION_STR "DDR TOOLS Revision: 01.00.00.00"

/*
 * ~~~~~ DO NOT EDIT BELOW ~~~~~
 */

#include <string.h>
#include "jacinto7_ddrss_address.h"
#include "jacinto7_ddrss_tools_lib.h"
#include "pattern_gen_lib.h"

//#include "uartStdio.h"
#include <ti/drv/uart/UART_stdio.h>

#include "board.h"
#include "board_cfg.h"
#if (defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_AM64X) || defined(SOC_J721S2))
#include "diag_common_cfg.h"
#endif

/*
 *  DEFINES - Do Not Change
 */
#define BITS_MAX            32
#define FREQ_MAX            3
#define CS_MAX              2
#define READ_EYE            0
#define WRITE_EYE           1
#define VREF_MIN            0x0
#define VREF_MAX_WRITE      0x48
#define VREF_MAX_READ       0x70
#define VREF_LP4R0_MAX      0x32
#define VREF_LP4R1_OFFSET   0x22
#define RDLY_MIN            0x0
#define RDLY_MAX            0x140

/*
 *  GLOBAL VARIABLES
 */
static unsigned int ddrss_base_addr;
static unsigned int sdram_base_addr;
static unsigned int bus_width;
static unsigned int rank_cnt;

static unsigned int eye_type;
static unsigned int vref_step_size;
static unsigned int dly_step_size;
// TODO static unsigned int pat_mask;

static unsigned int* buff_src;
static unsigned int* buff_result;
static unsigned int buff_size;
static unsigned int xfer_size;

// Change from TI code:
//   Adding local buffers to avoid usage of TI library
//   Size is based on:
//   buff_size = xfer_size = WC_ISI_SSO_4LANE_V3_SIZE*(bus_width/8);
static unsigned int buff_src_a[487872/4];
static unsigned int buff_result_a[487872/4];


static unsigned int data_fail_count[BITS_MAX * 2];

/*
 *  Function: clear_results
 *  Inputs: None
 *  Outputs: None
 *  Description: Clears fail statistics
 */
static void clear_results(void)
{
    unsigned int i;

    // zero fail count array
    for (i=0; i<BITS_MAX*2; i++)
    {
        data_fail_count[i] = 0;
    }
}

/*
 *  Function: print_results
 *  Inputs: None
 *  Outputs: None
 *  Description: Prints fail statistics per DQ & DQS edge
 */
static void print_results(void)
{
    unsigned int dqs_edge, bit;

    for (dqs_edge = 0; dqs_edge <= 1; dqs_edge++)
    {
        UART_printf("dqs_edge=%d\n", dqs_edge);

        for (bit=0; bit < bus_width; bit++)
        {
            UART_printf("%d\n", data_fail_count[dqs_edge*bus_width+bit]);
        }
    }
}

/*
 *  Function: jacinto7_ddrss_tools_mem_cmp
 *  Inputs: source, data, size, bit_results
 *      - source: address of source buffer
 *      - data: address of results buffer
 *      - size: size of buffer in bytes
 *      - bit_results: results array
 *  Outputs: None
 *  Description: Compares data to source and log results per DQ & DQS edge
 */
static void jacinto7_ddrss_tools_mem_cmp(unsigned int* source, unsigned int* data, unsigned int size, unsigned int* bit_results)
{
    unsigned int count, error_result, dqs_edge, bit, bit_mask;

    for(count = 0; count < (size / 4); count++)
    {
        // XOR result with expected value
        error_result = *source++ ^ *data++;

        // calculate strobe edge
        dqs_edge = (bus_width == 16) ? 0 : count % 2;

        // count fails for each bit and dqs edge
        for (bit=0; bit<32; bit++)
        {
            bit_mask = 1 << bit;

            bit_results[dqs_edge*32+bit] += (error_result & bit_mask) > 0 ? 1 : 0;
        }
    }
}

/*
 *  Function: jacinto7_ddrss_tools_save_trained_values
 *  Inputs: eye_type (READ_EYE or WRITE_EYE)
 *  Outputs: average delay value
 *  Description: Prints the trained VREF and delay settings
 *  TODO: Save to memory for restore
 */
static unsigned int jacinto7_ddrss_tools_save_trained_values(unsigned int eye_type)
{
    unsigned int cs, freq, count, value;
    volatile unsigned int total_val = 0;
    
    if(eye_type == WRITE_EYE){
        // TODO Fix to exclude F0 (requires update to perl script)
        for(count = 0; count < 12; count++)
        {
            value = jacinto7_ddrss_lp4_get_dram_vref(count);
            UART_printf("mr14_f%d_cs%d: 0x%08x\n", (count / 4), (count % 4), value);
        }
    }
    
    for(freq = 1; freq < FREQ_MAX; freq++)
    {
        jacinto7_ddrss_set_freq_index(freq-1);

        if(eye_type == READ_EYE){
            for(count = 0; count < (bus_width / 8); count++){
                value = jacinto7_ddrss_get_soc_vref(count);
                UART_printf("phy_vref_f%d_bl%d: 0x%x\n", freq, count, value);
            }
        }

        for(cs = 0; cs < rank_cnt; cs++)
        {
            jacinto7_ddrss_set_cs_index(cs);

            for(count = 0; count < bus_width; count++)
            {
                if(eye_type == WRITE_EYE){
                    value = jacinto7_ddrss_get_wrdly(count);
                    total_val += value;
                    UART_printf("write_delay, f%d_cs%d_dq%d : 0x%x\n", freq, cs, count, value);
                }else if(eye_type == READ_EYE){
                    value = jacinto7_ddrss_get_rddly_fall(count);
                    total_val += value;
                    UART_printf("read_delay_fall, f%d_cs%d_dq%d : 0x%x\n", freq, cs, count, value);

                    value = jacinto7_ddrss_get_rddly_rise(count);
                    total_val += value;
                    UART_printf("read_delay_rise, f%d_cs%d_dq%d : 0x%x\n", freq, cs, count, value);
                }
            }
        }
    }
    
    value = total_val / (bus_width * rank_cnt * (FREQ_MAX-1));
    
    return (eye_type == WRITE_EYE) ? value : (value / 2);
}

/*
 *  Function: jacinto7_ddrss_tools_lp4_write_margin
 *  Inputs: None
 *  Outputs: None
 *  Description: Loop through VREF and WRITE delay settings, capturing fail statistics
 *      1) Save WRITE training parameters
 *      2) Clear DDR memory and then write pattern to DDR
 *      3) For each VREF and READ delay setting,
 *          3a) Clear results
 *          3b) Clear DDR memory and then write pattern to DDR
 *          3c) Read pattern from DDR
 *          3d) Compare / log fail stats
 *          4e) Print fail stats
 */
static void jacinto7_ddrss_tools_lp4_write_margin (void)
{
    volatile unsigned int vref, vref_prog, vref_check, wrdly;
    volatile unsigned int chip_select = 0;
    volatile unsigned int mr14 = 0xe;
    volatile int status, avg_val;

    UART_printf("eye_type=write\n");
    avg_val = jacinto7_ddrss_tools_save_trained_values(WRITE_EYE);

    // for all VREF
    for(vref = VREF_MIN; vref <= VREF_MAX_WRITE; )
    {
        UART_printf("vref=%d\n", vref);

        // Overlap exists between range 0 / 1. Using full range of range 0; partial of range 1
        vref_prog = (vref > VREF_LP4R0_MAX) ? (vref + VREF_LP4R1_OFFSET) : vref;

        // Set VREF for DQ
        status = -1;
        while(status != 0){
            jacinto7_ddrss_lp4_mrw(chip_select, mr14, vref_prog);
            vref_check = 0xff & jacinto7_ddrss_lp4_mrr(chip_select, mr14);
            status = (vref_prog == vref_check) ? 0 : -1;
        }

        // for all write delays
        for(wrdly = (avg_val - 256); wrdly <= (avg_val + 256); )
        {
            UART_printf("wrdly=%d\n", wrdly);

            jacinto7_ddrss_set_wrdly(wrdly);

            jacinto7_ddrss_dll_manupd();

            clear_results();

            //TODO fix this to loop until full xfer_size cleared, written, read back, compared
            // currently xfer_size = buff_size

            // Clear DDR Memory
            memset((void *)sdram_base_addr, 0x0, buff_size);

            // Write Data to DDR Memory
            memcpy((void *)sdram_base_addr, (void *)buff_src, buff_size);

            // Read Data from DDR Memory
            memcpy((void *)buff_result, (void *)sdram_base_addr, buff_size);

            // Compare / log failures
            jacinto7_ddrss_tools_mem_cmp(buff_src, buff_result, buff_size, (unsigned int*)&data_fail_count);

            print_results();

            wrdly += dly_step_size;
        } // write delay

        vref += vref_step_size;
    } // vref

    // TODO restore training parameters
}


/*
 *  Function: jacinto7_ddrss_tools_lp4_read_margin
 *  Inputs: None
 *  Outputs: None
 *  Description: Loop through VREF and READ delay settings, capturing fail statistics
 *      1) Save READ training parameters
 *      2) Clear DDR memory and then write pattern to DDR
 *      3) For each VREF and READ delay setting,
 *          3a) Clear results
 *          3b) Read pattern from DDR
 *          3c) Compare / log fail stats
 *          4c) Print fail stats
 */
static void jacinto7_ddrss_tools_lp4_read_margin (void)
{
    unsigned int vref, rddly;

    UART_printf("eye_type=read\n");
    jacinto7_ddrss_tools_save_trained_values(READ_EYE);

    // TODO fix this to loop until full xfer_size cleared, written
    // currently xfer_size = buff_size

    // Clear DDR Memory
    memset((void *)sdram_base_addr, 0x0, buff_size);

    // Write Data to DDR Memory
    memcpy((void *)sdram_base_addr, (void *)buff_src, buff_size);

    // for all VREF
    for(vref = VREF_MIN; vref <= VREF_MAX_READ; )
    {
        UART_printf("vref=%d\n", vref);

        jacinto7_ddrss_set_soc_vref(vref);

        // for all read delays (test rise and fall at the same time)
        for(rddly = RDLY_MIN; rddly <= RDLY_MAX; )
        {
            UART_printf("rddly=%d\n", rddly);

            jacinto7_ddrss_set_rddly(rddly);

            jacinto7_ddrss_dll_manupd();

            clear_results();

            //TODO fix this to loop until full xfer_size read back, compared
            // Read Data from DDR Memory
            memcpy((void *)buff_result, (void *)sdram_base_addr, buff_size);

            // Compare / log failures
            jacinto7_ddrss_tools_mem_cmp(buff_src, buff_result, buff_size, (unsigned int*)&data_fail_count);

            print_results();

            rddly += dly_step_size;
        } // read delay

        vref += vref_step_size;
    } // vref

    // TODO restore training parameters
}

/*
 *  Function: jacinto7_ddrss_tools_get_ddr_config
 *  Inputs: None
 *  Outputs: None
 *  Description: Capture DRAM configuration and modify config for margin analysis
 *      1) User select DDRSS for analysis (TODO)
 *      2) Get DRAM parameters such as bus width / rank count
 *      3) Disable any periodic trainings / low power
 */
static void jacinto7_ddrss_tools_get_ddr_config(void)
{
    // Select DDRSS
    //TODO Add for future SOCs (j721e and j7200 share same base address / support LP4 only)
    UART_printf("DDRSS Instance: %d\n", 0);
    UART_printf("\tDRAM Type: LPDDR4\n");
    ddrss_base_addr = J721E_DDRSS_BASE;
    sdram_base_addr = J721E_SDRAM_ADDR;

    // Get bus width config of desired DDRSS
    bus_width = jacinto7_ddrss_get_bus_width(ddrss_base_addr);
    UART_printf("\tBus Width: %d\n", bus_width);

    // Get rank count config of desired DDRSS
    rank_cnt = jacinto7_ddrss_get_rank_cnt(ddrss_base_addr);
    UART_printf("\tRank Count: %d\n", rank_cnt);

    // Disable periodic trainings to prevent conflicts with manual programming
    jacinto7_ddrss_disable_per_wrdq_train(ddrss_base_addr);

    // Setup DDRSS for eye
    jacinto7_ddrss_tool_cfg(ddrss_base_addr);
}

/*
 *  Function: jacinto7_ddrss_tools_marginAnalysis_config
 *  Inputs: None
 *  Outputs: None
 *  Description: Configures global variables based on user input
 *      1) Select read / write margin analysis type
 *      2) Select step size for VREF / DLL
 *      3) Select pattern and xfer size (TODO)
 *      4) Allocate memory and generate pattern
 */
uint32_t UART_getNum(void);
static void jacinto7_ddrss_tools_marginAnalysis_config(void)
{
    char    rxByte;

    UART_printf("\nMargin Analysis Input:\n");

    // Select margin analysis type (read / write)
    UART_printf("\tEye Type (Select '%d' for read, '%d' for write): ", READ_EYE, WRITE_EYE);
    rxByte = (char) UART_getc();
    eye_type = (((uint32_t)(rxByte)) - 0x30U);
    UART_printf("%d\n", eye_type);

    // Select step size for VREF and DLL
    UART_printf("\tEye Precision (VREF / DLL Step Size; impacts test time):\n");
    UART_printf("\t\tVREF Step Size (enter decimal value; min value is 2): ");
    //rxByte = (char) UART_getc();
    //vref_step_size = (((uint32_t)(rxByte)) - 0x30U);
    vref_step_size = 4;
    UART_printf("%d\n", vref_step_size);

    UART_printf("\t\tDelay Step Size (enter decimal value; min value is 8): ");
    //rxByte = (char) UART_getc();
    //dly_step_size = (((uint32_t)(rxByte)) - 0x30U);
    dly_step_size = 16;
    UART_printf("%d\n", dly_step_size);

    // Select pattern, pattern mask, and xfer size (not user configurable)
    //TODO
    UART_printf("\tPattern: ""wc_isi_sso""\n");
    //pat_mask = 0xFFFFFFFF;
    buff_size = xfer_size = WC_ISI_SSO_4LANE_V3_SIZE*(bus_width/8);
    UART_printf("\tTransfer Size (bytes): %d\n", xfer_size);
    // Altering the TI library usage as it causes the Stelantis Custom board code to hang
    // Replace the memory allocation and buffer fill
    //buff_src = pat_gen_wc_isi_sso(bus_width, 16);
    buff_src = buff_src_a;
    // Fill in alternating memory
    for (int i = 0; i < xfer_size/4; i++) {
        if (i < xfer_size/8) {
            if ((i / 4) % 2 == 0) {
                buff_src_a[i] = 0x55555555;
            } else {
                buff_src_a[i] = 0xAAAAAAAA;
            }
        } else {
            if ((i / 4) % 2 == 0) {
                buff_src_a[i] = 0x99999999;
            } else {
                buff_src_a[i] = 0x66666666;
            }
        }
    }
    UART_printf("\tcreated buff_src, size %d\n", sizeof(buff_src_a));
    // Altering the TI library usage as this causes the Stellantis Custom board code to hang
    // Replace the memory allocation with locally created buffer
    //buff_result = pat_gen_empty_buff(buff_size, bus_width, 16);
    buff_result = buff_result_a;
    UART_printf("\tcreated buff_result, size %d\n", sizeof(buff_result_a));
}

/*
 *  Function: jacinto7_ddrss_tools_header
 *  Inputs: None
 *  Outputs: None
 *  Description: Print high level tool info
 */
static void jacinto7_ddrss_tools_header(void)
{
    UART_printf("Jacinto7 DDRSS Tools\n");
    UART_printf("Supported SOCs: J721E, J7200\n");
    UART_printf("Revision: Beta Release - September 2020 \n\n");
    UART_printf("%s (%s - %s)\n", DDRTOOLS_VERSION_STR, __DATE__, __TIME__);
}

/* Write to an MMR. */
static void Write_MMR(unsigned int mmr_address, unsigned int mmr_value){
    unsigned int * p_mmr;
    p_mmr = (unsigned int *) mmr_address;
    *p_mmr = mmr_value;
}

/* Write to a specific field in an MMR. */
static void Write_MMR_Field(unsigned int mmr_address, unsigned int field_value, unsigned int width, unsigned int leftshift){
    unsigned int * p_mmr;
    unsigned int mask;
    p_mmr = (unsigned int *) mmr_address;   //Grab the MMR value
    mask = ((1 << width) - 1) << leftshift; //Build a mask of 1s for the field.
    mask = ~(mask); //Invert the mask so that the field will be zero'd out with the AND operation.
    *p_mmr &= mask; //Zero out the field in the register.
    *p_mmr |= (field_value << leftshift); //Assign the value to that specific field.
}

static void J721E_Configure_UART0_PINMUX(void)
{
    //Write_MMR(0x0011D008, 0x68EF3490);
    //Write_MMR(0x0011D00C, 0xD172BC5A);

    // UART0
    Write_MMR(0x0011C1E8, 0x00050000);  //RX
    Write_MMR(0x0011C1EC, 0x00010000);  //TX
}

static void J721E_Configure_MCU_R5_RAT(void)
{
    Write_MMR(0x40F90024, 0x60000000);
    Write_MMR(0x40F90028, 0x00000000);
    Write_MMR(0x40F9002C, 0x0000004F);
    Write_MMR(0x40F90020, 0x00000017);
    Write_MMR_Field(0x40F90020, 1, 1, 31);
}

volatile uint32_t debug_var = 0;
int main ()
{
    Board_STATUS status;
    Board_initCfg boardCfg;

    //while(debug_var == 0);
    //Configure Board
    //J721E_Configure_UART0_PINMUX();
    J721E_Configure_MCU_R5_RAT();


    // Configure UART
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG ;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    // Print tool info
    jacinto7_ddrss_tools_header();
    UART_printf("Jacinto7 header done\n");

    // Select DDRSS, get DRAM config, and setup DDRSS for analysis
    jacinto7_ddrss_tools_get_ddr_config();
    UART_printf("Jacinto7 get_ddr_config done\n");

    // Select user options for margin analysis
    jacinto7_ddrss_tools_marginAnalysis_config();
    UART_printf("Jacinto7 marginAnaysis_config done\n");

    // Only supports either read or write; to run both, must re-configure device and re-run code
    if(eye_type == READ_EYE){
        jacinto7_ddrss_tools_lp4_read_margin();
    }else{
        jacinto7_ddrss_tools_lp4_write_margin();
    }
    UART_printf("Jacinto7 DDRSS Tools Completed\n");
    while(1);
}
