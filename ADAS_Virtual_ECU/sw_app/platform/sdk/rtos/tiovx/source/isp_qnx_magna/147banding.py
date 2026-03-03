import os
import time
import math

from reg147 import *

def bf(val, mask):
    c = 0
    m = mask
    for i in range(64):
        if m & 1 != 0:
            break
        m>>= 1
        c+=1
    return (val & mask) >> c

class reg():
    def __init__(self, addr):
        self.addr = addr
        self.value = int(t[addr])
    def bitfield(self, mask):
        return bf(self.value, mask)

var1 = None



def check(CIT):
    #Constants
    y_addr_start_status = ""
    y_addr_end_status = ""
    row_band_fix = 0
    T2_Gain = 4
    T2_Barrier = 3800
    Min_DLO_Gain3_120dB = (2**20)/T2_Barrier
    vt_pix_clk_div = reg(0x302A).value
    pre_pll_clk_div = reg(0x302E).value
    pll_multiplier = reg(0x3030).value
    FLL = reg(0x300A).value
    LLPCK = reg(0x300C).value
    DBLC_BTM_Row = reg(0x33E4).bitfield(0x00F0)
    y_addr_start = 0#reg(0x3002).value
    y_addr_end = reg(0x3006).value
    vertical_flip = reg(0x3040).bitfield(0x8000)
    se_mode = reg(0x33E2).bitfield(0x0700)
    AB_period = reg(0x3252).bitfield(0x00FF)
    t3_sh_adv = reg(0x32EC).bitfield(0x00C0)
    t4_sh_adv = reg(0x32EC).bitfield(0x0300)
    FIT = reg(0x3014).value
    FIT4 = reg(0x3226).value
    CIT2 = 0
    CIT3 = 0 #reg(0x3216).value
    GCF_TG_1P5 = 0xE8 #reg(0x3F74).bitfield(0x00FF)
    DCG_Ratio = GCF_TG_1P5/16

    if (vertical_flip == 0):
        if (y_addr_start % 16 != 0):
            y_addr_start_status = "--> ERROR: Y_ADDR_START is not Modulo 16"
        start_pointer = math.ceil(y_addr_start/16) + 2*row_band_fix
        stop_pointer = 0
    else:
        if ((967-y_addr_end) % 16 != 0):
            y_addr_end_status = "--> ERROR: Y_ADDR_END is not Modulo 16"
        start_pointer = 0
        if (y_addr_end == 967):
            if (row_band_fix):
                stop_pointer = 60
            else:
                stop_pointer = 0
        else:
            stop_pointer = math.ceil(y_addr_end/16) - row_band_fix
    T1_inPclk = (CIT - 1)*LLPCK + FIT
    Max_T2_inPCLK = (T1_inPclk*DCG_Ratio + T1_inPclk + T1_inPclk)/(Min_DLO_Gain3_120dB*T2_Gain - T2_Gain)
    CIT4 = math.floor(((Max_T2_inPCLK-FIT4)/(LLPCK))+1)
    if (CIT4 > 18):
        CIT4_Cond = "Limit above Max of 18 rows"
    else:
        CIT4_Cond = ""
    if (se_mode == 2):
        var1 = CIT3 + t3_sh_adv
    else:
        if (se_mode == 5):
            var1 = CIT4 + t4_sh_adv
        else:
            var1 = 0

    num_pulse = math.floor(CIT/(AB_period + 1))
    if (DBLC_BTM_Row != 0):
        add2dblcBtm = 4
    else:
        add2dblcBtm = 0
    dblc_btm_add = 12 - (add2dblcBtm + DBLC_BTM_Row)

    if (CIT > FLL-11-var1):
        CITchoosenState = "TX_PULSING DISABLED"
    else:
        if(num_pulse < 1):
            CITchoosenState = "NO TX_PULSE"
        else:
            if(row_band_fix):
                CITchoosenState = "GOOD, row band is fixed"
            else:
                if(vertical_flip == 1):
                    state1 = bool(((CIT-1-dblc_btm_add+((y_addr_end+AB_period+1)%(AB_period+1)))%(AB_period+1))== 0)
                    state2 = bool(((CIT-3-dblc_btm_add+((y_addr_end+AB_period+1)%(AB_period+1)))%(AB_period+1))== 0)
                    state3 = bool(((CIT-2-dblc_btm_add+((y_addr_end+AB_period+1)%(AB_period+1)))%(AB_period+1))== 0)
                    if(state1 or state2 or state3):
                        CITchoosenState = "BANDING"
                    else:
                        CITchoosenState = "GOOD"
                else:
                    if (start_pointer > 1):
                        start_pointer_val = 2
                    else:
                        start_pointer_val = 0
                    state4 = bool(((CIT-1-dblc_btm_add-start_pointer_val)%(AB_period+1))== 0)
                    state5 = bool(((CIT-3-dblc_btm_add-start_pointer_val)%(AB_period+1))== 0)
                    state6 = bool(((CIT-2-dblc_btm_add-start_pointer_val)%(AB_period+1))== 0)
                    if(state4 or state5 or state6):
                        CITchoosenState = "BANDING"
                    else:
                        CITchoosenState = "GOOD"
    return CITchoosenState, CIT4

def _main():
    extclk_mhz = 24
    print(extclk_mhz, "MHz")
    #Constants
    y_addr_start_status = ""
    y_addr_end_status = ""
    row_band_fix = 0
    T2_Gain = 4
    T2_Barrier = 3800
    Min_DLO_Gain3_120dB = (2**20)/T2_Barrier
    vt_pix_clk_div = reg(0x302A).value
    pre_pll_clk_div = reg(0x302E).value
    pll_multiplier = reg(0x3030).value
    FLL = reg(0x300A).value
    LLPCK = reg(0x300C).value
    DBLC_BTM_Row = reg(0x33E4).bitfield(0x00F0)
    y_addr_start = 0 #reg(0x3002).value
    y_addr_end = reg(0x3006).value
    vertical_flip = reg(0x3040).bitfield(0x8000)
    se_mode = reg(0x33E2).bitfield(0x0700)
    AB_period = reg(0x3252).bitfield(0x00FF)
    t3_sh_adv = reg(0x32EC).bitfield(0x00C0)
    t4_sh_adv = reg(0x32EC).bitfield(0x0300)
    FIT = reg(0x3014).value
    FIT4 = reg(0x3226).value
    CIT2 = 0
    CIT3 = 0 #reg(0x3216).value
    GCF_TG_1P5 = 0xE8 #reg(0x3F74).bitfield(0x00FF)
    DCG_Ratio = GCF_TG_1P5/16


    print("vt_pix_clk_div = %s" % vt_pix_clk_div)
    print("pre_pll_clk_div = %s" % pre_pll_clk_div)
    print("pll_multiplier = %s" % pll_multiplier)
    print("fll = %s" % FLL)
    print("llpck = %s" % LLPCK)
    print("dblc_btm_row = %s" % DBLC_BTM_Row)
    print("y_addr_start = %s" % y_addr_start)
    print("y_addr_end = %s" % y_addr_end)
    print("vertical_flip = %s" % vertical_flip)
    print("se_mode = %s" % se_mode)
    print("ab_period = %s" % AB_period)
    print("t3_sh_adv = %s" % t3_sh_adv)
    print("t4_sh_adv = %s" % t4_sh_adv)
    print("fit = %s" % FIT)
    print("fit4 = %s" % FIT4)
    print("Flip Mode: ",vertical_flip)
    print("se_mode: ",se_mode)

    if (se_mode == 0):
        print ("Mode: Linear Mode")
    elif (se_mode == 5):
        print ("Mode: Super Exposure + T2")
    elif (se_mode == 6):
        print ("Mode: Super Exposure")
    else:
        print ("Mode: Not Supported")
    if (vertical_flip == 0):
        if (y_addr_start % 16 != 0):
            y_addr_start_status = "--> ERROR: Y_ADDR_START is not Modulo 16"
        start_pointer = math.ceil(y_addr_start/16) + 2*row_band_fix
        stop_pointer = 0
    else:
        if ((967-y_addr_end) % 16 != 0):
            y_addr_end_status = "--> ERROR: Y_ADDR_END is not Modulo 16"
        start_pointer = 0
        if (y_addr_end == 967):
            if (row_band_fix):
                stop_pointer = 60
            else:
                stop_pointer = 0
        else:
            stop_pointer = math.ceil(y_addr_end/16) - row_band_fix
    print("Y_Addr_Start: ", y_addr_start, " ", y_addr_start_status)
    print("Y_Addr_End: ", y_addr_end, " ", y_addr_end_status)
    print("start_pointer: ",start_pointer)
    print("stop_pointer: ",stop_pointer)
    pix_clk = (extclk_mhz * pll_multiplier)/(vt_pix_clk_div*pre_pll_clk_div)
    row_time = round(LLPCK/pix_clk,0)
    CIT = int(input("Enter the Coarse Integration Time (CIT): "))
    print(CIT, "rows")
    T1_inPclk = (CIT - 1)*LLPCK + FIT
    Max_T2_inPCLK = (T1_inPclk*DCG_Ratio + T1_inPclk + T1_inPclk)/(Min_DLO_Gain3_120dB*T2_Gain - T2_Gain)
    CIT4 = math.floor(((Max_T2_inPCLK-FIT4)/(LLPCK))+1)
    if (CIT4 > 18):
        CIT4_Cond = "Limit above Max of 18 rows"
    else:
        CIT4_Cond = ""
    if (se_mode == 2):
        var1 = CIT3 + t3_sh_adv
    else:
        if (se_mode == 5):
            var1 = CIT4 + t4_sh_adv
        else:
            var1 = 0

    num_pulse = math.floor(CIT/(AB_period + 1))
    if (DBLC_BTM_Row != 0):
        add2dblcBtm = 4
    else:
        add2dblcBtm = 0
    dblc_btm_add = 12 - (add2dblcBtm + DBLC_BTM_Row)

    print("dblc_btm_add ", dblc_btm_add)

    if (CIT > FLL-11-var1):
        CITchoosenState = "TX_PULSING DISABLED"
    else:
        if(num_pulse < 1):
            CITchoosenState = "NO TX_PULSE"
        else:
            if(row_band_fix):
                CITchoosenState = "GOOD, row band is fixed"
            else:
                if(vertical_flip == 1):
                    state1 = bool(((CIT-1-dblc_btm_add+((y_addr_end+AB_period+1)%(AB_period+1)))%(AB_period+1))== 0)
                    state2 = bool(((CIT-3-dblc_btm_add+((y_addr_end+AB_period+1)%(AB_period+1)))%(AB_period+1))== 0)
                    state3 = bool(((CIT-2-dblc_btm_add+((y_addr_end+AB_period+1)%(AB_period+1)))%(AB_period+1))== 0)
                    if(state1 or state2 or state3):
                        CITchoosenState = "BANDING"
                    else:
                        CITchoosenState = "GOOD"
                else:
                    if (start_pointer > 1):
                        start_pointer_val = 2
                    else:
                        start_pointer_val = 0
                    state4 = bool(((CIT-1-dblc_btm_add-start_pointer_val)%(AB_period+1))== 0)
                    state5 = bool(((CIT-3-dblc_btm_add-start_pointer_val)%(AB_period+1))== 0)
                    state6 = bool(((CIT-2-dblc_btm_add-start_pointer_val)%(AB_period+1))== 0)
                    print("states = ", state4, state6, state5)
                    if(state4 or state5 or state6):
                        CITchoosenState = "BANDING"
                    else:
                        CITchoosenState = "GOOD"
    print("---------------------------------------------------------------------------")
    print("Based on CIT setting of, ",CIT, " rows. Result is: ", CITchoosenState)
    print("Set T2 (CIT4 in DevWare, max is 18 rows) to: ", CIT4, " ", CIT4_Cond)
    print("---------------------------------------------------------------------------")
    print("\n")

#_main()

for i in range(20, 1024):
   r, c4 = check(i)
   print("%04d (%04d): %s" % (i, c4, r))