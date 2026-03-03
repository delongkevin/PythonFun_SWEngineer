/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Crypto_30_vHsm
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_vHsm_Custom_Generated.h
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_VHSM_CUSTOM_GENERATED_H)
#define CRYPTO_30_VHSM_CUSTOM_GENERATED_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Symbolic Name Define Block ---------------------------------------------- */
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_ForceSequential      133u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_PersistDeferred      152u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_Repersist            153u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_LibCv_P256r1                   128u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_ServiceCertificate        140u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_CertElementGet            141u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_CertElementGetFirst       142u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_CertElementGetNext        143u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBoot         160u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_FirmwareUpdate     163u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootUpdate   164u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SoftwareDownload   161u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootConfirmation 165u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_Persistency        192u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_Hwa_PaddingPKCS7             133u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_PaddingPKCS7           133u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_DRBG                   131u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_KeyM_vHsm_KeyM               170u

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_FORCESEQUENTIAL                             CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_ForceSequential
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_PERSISTDEFERRED                             CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_PersistDeferred
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_REPERSIST                                   CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_Repersist
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_LIBCV_P256R1                                          CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_LibCv_P256r1
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_KEYM_SERVICECERTIFICATE                               CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_ServiceCertificate
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_KEYM_CERTELEMENTGET                                   CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_CertElementGet
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_KEYM_CERTELEMENTGETFIRST                              CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_CertElementGetFirst
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_KEYM_CERTELEMENTGETNEXT                               CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_KeyM_CertElementGetNext

/* ----- Custom Algorithm Family Defines ---------------------------------------------- */
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SECUREBOOT                                   CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBoot
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_FIRMWAREUPDATE                               CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_FirmwareUpdate
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SECUREBOOTUPDATE                             CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootUpdate
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SOFTWAREDOWNLOAD                             CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SoftwareDownload
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SECUREBOOTCONFIRMATION                       CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootConfirmation
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_PERSISTENCY                                  CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_Persistency
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_HWA_PADDINGPKCS7                                       CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_Hwa_PaddingPKCS7
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_LIBCV_PADDINGPKCS7                                     CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_PaddingPKCS7
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_LIBCV_DRBG                                             CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_DRBG
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_KEYM_VHSM_KEYM                                         CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_KeyM_vHsm_KeyM

#endif /* CRYPTO_30_VHSM_CUSTOM_GENERATED_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Custom_Generated.h
 *********************************************************************************************************************/

