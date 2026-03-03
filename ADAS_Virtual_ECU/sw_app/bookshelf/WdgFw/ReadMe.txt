Date: 04/14/2023
Author: Pramod Kumar
Veriov: 2.0


Topic
======
WdgFw folder structure

Description
===========
Wdg framework has multiple software component with different folder name and applicable for multiple core. 
This makes WdgFw folder stucture little complicated.

|==============|============================|=======================================|============================================
|    SWC       |    Applicable to Cores     |      Path                             | Comment                                   |
|==============|============================|=======================================|============================================
| WDG (Magna)  |    MCU1_0, MCU2_0, MCU2_1  | common\magna_basesw\WdgFw\Wdg         | Inhouse developed                         |
|              |    MPU1_0					|                                       |                                           |
|--------------|----------------------------|---------------------------------------|--------------------------------------------
| WDGIF        |    MCU1_0		            | common\autosar\vector_stack\WdgIf     | AutoSAR Code                              |
|--------------|----------------------------|---------------------------------------|--------------------------------------------
| WDGIF (Magna)|    MPU1_0		            | common\magna_basesw\WdgFw\WdgIf       | Modified AutoSAR Code                     |
|              |----------------------------|---------------------------------------|--------------------------------------------
|              |    MCU2_0, MCU2_1          | common\magna_basesw\WdgFw\WdgIf_Magna | SafeRTOS checkpoint                       |
|--------------|----------------------------|---------------------------------------|--------------------------------------------
| WDGM         |    MCU1_0  	            | common\autosar\vector_stack\WdgM      | AutoSAR Code                              |
|--------------|----------------------------|---------------------------------------|--------------------------------------------
| WDGM (Magna) |    MPU1_0       		    | common\magna_basesw\WdgFw\WdgM        | Modified AutoSAR Code                     |
|              |----------------------------|---------------------------------------|--------------------------------------------
|              |    MCU2_0,MCU2_1           | common\magna_basesw\WdgFw\WdgM_Magna  | SafeRTOS checkpoint                       |
|--------------|----------------------------|---------------------------------------|--------------------------------------------
| WDGSLAVE     |    MCU1_0                  | common\magna_basesw\WdgFw\WdgSlave    | This SWC only applicable to MCU1_0        |
|--------------|----------------------------|---------------------------------------|--------------------------------------------

