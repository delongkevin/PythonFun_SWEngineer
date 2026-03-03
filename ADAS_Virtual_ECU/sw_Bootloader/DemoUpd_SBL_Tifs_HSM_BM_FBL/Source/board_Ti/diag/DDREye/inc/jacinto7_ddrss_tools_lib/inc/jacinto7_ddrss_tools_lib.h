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

#ifndef JACINTO7_DDRSS_TOOLS_LIB_H_
#define JACINTO7_DDRSS_TOOLS_LIB_H_

unsigned int jacinto7_ddrss_get_bus_width (unsigned int base_addr);
unsigned int jacinto7_ddrss_get_rank_cnt (unsigned int base_addr);
void jacinto7_ddrss_disable_per_wrdq_train(unsigned int base_addr);
void jacinto7_ddrss_tool_cfg(unsigned int base_addr);

// PHY Indexing Functions
void jacinto7_ddrss_set_freq_index(unsigned int freq);
void jacinto7_ddrss_set_cs_index(unsigned int cs);

// PHY Delay Functions
void jacinto7_ddrss_dll_manupd(void);
void jacinto7_ddrss_set_rddly(unsigned int rddly);
void jacinto7_ddrss_set_wrdly(unsigned int wrdly);
unsigned int jacinto7_ddrss_get_rddly_fall(unsigned int bit);
unsigned int jacinto7_ddrss_get_rddly_rise(unsigned int bit);
unsigned int jacinto7_ddrss_get_wrdly(unsigned int bit);

// PHY VREF Functions
void jacinto7_ddrss_set_soc_vref(unsigned int vref);
unsigned int jacinto7_ddrss_get_soc_vref(unsigned int byte_lane);

// LP4 DRAM VREF Functions
unsigned int jacinto7_ddrss_lp4_get_dram_vref(unsigned int count);

// LP4 Mode Register Read / Write Functions
unsigned int jacinto7_ddrss_lp4_mrr (unsigned int chip_select, unsigned int mr_addr);
int jacinto7_ddrss_lp4_mrw (unsigned int chip_select, unsigned int mr_addr, unsigned int mr_data);


#endif /* JACINTO7_DDRSS_TOOLS_LIB_H_ */
