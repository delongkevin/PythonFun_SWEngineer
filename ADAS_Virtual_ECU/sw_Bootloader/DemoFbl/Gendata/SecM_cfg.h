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
 *            Module: Smh
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecM_cfg.h
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#if !defined(SECM_CFG_H)
#define SECM_CFG_H

#define SEC_CLASS_DDD                         0u
#define SEC_CLASS_C                           1u
#define SEC_CLASS_CCC                         2u
#define SEC_CLASS_VENDOR                      3u
#define SEC_DEVELOPMENT                       1u
#define SEC_PRODUCTION                        2u
#define SEC_ADDRESS                           1u
#define SEC_FILE                              2u
#define SEC_CRC_SPEED_OPTIMIZED               0u
#define SEC_CRC_SIZE_OPTIMIZED                1u
#define SEC_CRC_MODE_NON_REFLECTED            0u
#define SEC_CRC_MODE_REFLECTED                1u
#define SEC_RIPEMD160                         0u
#define SEC_SHA1                              1u
#define SEC_SHA256                            2u
#define SEC_SHA512                            3u
#define SEC_AES128                            0u
#define SEC_AES192                            1u
#define SEC_AES256                            2u
#define SEC_CRC16_CCITT                       1u
#define SEC_CRC16                             SEC_CRC16_CCITT
#define SEC_CRC32                             0u
#define SEC_CRC64                             2u
#define SEC_CHECKSUM_TYPE_CRC                 0u
#define SEC_CHECKSUM_TYPE_HASH                1u
#define SEC_RSA_KEY_LENGTH_1024               0u
#define SEC_RSA_KEY_LENGTH_1536               1u
#define SEC_RSA_KEY_LENGTH_2048               2u
#define SEC_RSA_KEY_LENGTH_3072               3u
#define SEC_RSA_KEY_LENGTH_4096               4u
#define SEC_SIGNATURE_SCHEME_RSA_V15          0u
#define SEC_SIGNATURE_SCHEME_RSA_PSS          1u
#define SEC_SIGNATURE_SCHEME_ECDSA_CURVE25519 2u
#define SEC_SIGNATURE_SCHEME_ECDSA_CURVEP256  3u

#define SEC_INVALID_SMH_KEY_ID                0xFFFFFFFFu
#define SEC_INVALID_SMH_JOB_ID                0xFFFFFFFFu
#define SEC_INVALID_CSM_KEY_ID                0xFFFFFFFFu
#define SEC_INVALID_CSM_JOB_ID                0xFFFFFFFFu

/* SmhConf macros */
#define SmhConf_SmhStreamVerificationHash_SmhSecurityClassDDDConfig      0x00000000u 
#define SmhConf_SmhStreamVerificationSignature_SmhSecurityClassCCCConfig 0x00000000u 
#define SmhConf_SmhJob_SmhJob_TRNG                                       0x00000000u 
#define SmhConf_SmhJob_SmhJob_SignatureVerify                            0x00000001u 
#define SmhConf_SmhJob_Smh_GetCertificateElement                         0x00000002u 
#define SmhConf_SmhJob_SmhJob_CalculateHash                              0x00000003u 


/* SizeOf macros */
#define SecM_GetSizeOfDecryptionPrimitives() 0x00000000u 
#define SecM_GetSizeOfCrcPrimitives()        0x00000000u 
#define SecM_GetSizeOfHashPrimitives()       0x00000001u 
#define SecM_GetSizeOfSignaturePrimitives()  0x00000001u 
#define SecM_GetSizeOfJobInfo()              0x00000004u 
#define SecM_GetSizeOfCryptogrphicKeys()     0x00000000u 


/* General defines */
#define SEC_MODE                 SEC_PRODUCTION 
#define SEC_WATCHDOG_CYCLE_COUNT 0x00000001u 


/* General switches */
#define SEC_DISABLE_KEY_LOCATION_RAM 
#define SEC_DISABLE_CRYPTOGRAPHIC_KEYS 
#define SEC_ENABLE_CSM 


/* CRC defines */
#define SEC_SIZE_CHECKSUM_CRC SEC_SIZE_CHECKSUM_CRC_32 
#define SEC_CRC_32_OPT        SEC_CRC_SPEED_OPTIMIZED 
#define SEC_CRC_32_INITIAL    0xFFFFFFFFu 
#define SEC_CRC_32_POLYNOMIAL 0xEDB88320u 
#define SEC_CRC_32_MODE       SEC_CRC_MODE_REFLECTED 
#define SEC_CRC_32_FINAL      0xFFFFFFFFu 
#define SEC_CRC_TYPE          SEC_CRC32 


/* CRC switches */
#define SEC_ENABLE_CRC 
#define SEC_DISABLE_CRC_TYPE_CRC16 
#define SEC_ENABLE_CRC_TYPE_CRC32 
#define SEC_DISABLE_CRC_TYPE_CRC64 


/* Encryption defines */
#define SEC_KEY_TIMEOUT 100u 
#define SEC_CALL_CYCLE  10u 


/* Encryption switches */
#define SEC_DISABLE_DECRYPTION 
#define SEC_DISABLE_ENCRYPTION 



/* Stream Verification defines */
#define SEC_SECURITY_CLASS_VERIFY SEC_CLASS_DDD 
#define SecM_VerifySignature      SecM_VerifySHA256 
#define SecM_VerifyClassDDD       SecM_VerifySHA256 
#define SecM_VerifyClassCCC       SecM_AuthDiag_Certificate_VerifySign 
#define SEC_SIZE_CHECKSUM_VENDOR  0x00000001u 
#define SecM_VerifyClassVendor    SecM_VerifyClassVendorStream 


/* Stream Verification switches */
#define SEC_DISABLE_VERIFY_CRC 
#define SEC_ENABLE_VERIFY_HASH 
#define SEC_ENABLE_VERIFY_SIGNATURE 
#define SEC_DISABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING 
#define SEC_DISABLE_VERIFICATION_DISCRETE_HASH_CALC 


/* Monolithic Verification defines */
#define SecM_Verification                       SecM_VerifyClassVendorBlock 
#define SEC_SECURITY_CLASS_VERIFICATION         SEC_CLASS_VENDOR 
#define SEC_SECURITY_CLASS                      SEC_SECURITY_CLASS_VERIFICATION 
#define SEC_VER_SIG_OFFSET                      0x00000000u 
#define SEC_VER_CRC_OFFSET                      0x00000000u 
#define SecM_VerificationClassDDD               SecM_VerificationClassDDD_SHA256 
#define SecM_VerificationClassVendor            SecM_VerifyClassVendorBlock 
#define SEC_VERIFY_CLASS_DDD_DIGEST_SIZE        SEC_SIZE_HASH_SHA256 
#define SEC_VERIFY_CLASS_DDD_VERIFY_SIZE        SEC_SIZE_HASH_SHA256 
#define SEC_VERIFY_CLASS_DDD_VERIFY_OFFSET      0x00000002u 
#define SEC_VERIFY_CLASS_DDD_CHECKSUM_OFFSET    0x00000002u 
#define SEC_VERIFY_CLASS_VENDOR_CHECKSUM_OFFSET 0x00000000u 
#define SEC_MEMORY_ACCESS                       SEC_ADDRESS 
#define SEC_VERIFY_BYTES                        0x0040u 
#define SEC_VER_MAX_CONFIG_COUNT                0x0004u 


/* Monolithic Verification switches */
#define SEC_ENABLE_SECURITY_CLASS_DDD 
#define SEC_ENABLE_SECURITY_CLASS_VENDOR 
#define SEC_DISABLE_CRC_TOTAL 
#define SEC_DISABLE_CRC_WRITTEN 
#define SEC_DISABLE_CRC_WRITTEN_GET 
#define SEC_DISABLE_VERIFICATION_ASSERT_READ_COUNT 
#define SEC_DISABLE_VERIFICATION_RANGE_CHECK 
#define SEC_DISABLE_VERIFICATION_WRAPPER 
#define SEC_DISABLE_VERIFICATION_ADDRESS_LENGTH 
#define SEC_DISABLE_VERIFICATION_DATA_LENGTH 
#define SEC_DISABLE_VENDOR_CHECKSUM 


/* SmhJob switches */
#define SEC_DISABLE_JOB_INITKEY_AES 
#define SEC_DISABLE_JOB_INITKEY_MAC 
#define SEC_DISABLE_JOB_INITKEY_SYMMETRIC 
#define SEC_ENABLE_JOB_INITKEY_ASYMMETRIC 
#define SEC_DISABLE_JOB_INITKEY_PBKDF2 
#define SEC_ENABLE_JOB_HASH 
#define SEC_ENABLE_JOB_RANDOMGENERATE 
#define SEC_DISABLE_JOB_MACVERIFY 
#define SEC_DISABLE_JOB_MACGENERATE 
#define SEC_DISABLE_JOB_ENCRYPTION 
#define SEC_DISABLE_JOB_DECRYPTION 
#define SEC_ENABLE_JOB_SIGNATUREVERIFY 
#define SEC_DISABLE_JOB_RANDOMSEED 
#define SEC_ENABLE_JOB_AEADENCRYPT 
#define SEC_DISABLE_JOB_AEADDECRYPT 
#define SEC_DISABLE_JOB_KEYDERIVE 


/* SmhJob macros */
#define Smh_GetCertificateElement_ADACert(mode, plaintextPtr, plaintextLength, associatedDataPtr, associatedDataLength, ciphertextPtr, ciphertextLengthPtr, tagPtr, tagLengthPtr) \
 SecM_AEADEncrypt_Job(SmhConf_SmhJob_Smh_GetCertificateElement, (mode), (plaintextPtr), (plaintextLength), (associatedDataPtr), (associatedDataLength), (ciphertextPtr), (ciphertextLengthPtr), (tagPtr), (tagLengthPtr)) 


/* SeedKey defines */
#define SEC_ENTROPY_POOL_SIZE                      0x00000000u 
#define SEC_LCG_RANDOM_INCREMENT                   0x2AA01D31u 
#define SEC_LCG_RANDOM_MULTIPLIER                  0x7FF8A3EDu 
#define SEC_PRNG_GENERATE_RANDOM(pRandom, pLength) SecM_GenerateRandomLcg((pRandom), (pLength)) 
#define SEC_SEED_LENGTH                            0x00000004u 
#define SEC_ECU_KEY                                0xFFFFFFFFu 
#define SEC_KEY_LENGTH                             0x00000004u 
#define SEC_SECRET_KEY_LENGTH                      0x00000000u 


/* SeedKey switches */
#define SEC_ENABLE_SEEDKEY 
#define SEC_DISABLE_SEED_KEY_ENTROPY_POOL 
#define SEC_DISABLE_SEED_KEY_IMPLICIT_ENTROPY 
#define SEC_DISABLE_SEED_KEY_EXPLICIT_ENTROPY 
#define SEC_ENABLE_SEED_KEY_PRNG_LCG 
#define SEC_DISABLE_SEED_KEY_EXTERNAL_COMPARISION 
#define SEC_DISABLE_SEED_KEY_EXTENDED_API 
#define SEC_DISABLE_SEED_KEY_ASYMMETRIC 


/* Cryptographic defines */
#define SEC_KE_RSA_MODULUS          160u 
#define SEC_KE_RSA_PUBLIC_EXPONENT  161u 
#define SEC_KE_RSA_PRIVATE_EXPONENT 162u 


/* Key operation switches */
#define SEC_ENABLE_KEY_OPERATION_ACCESS 
#define SEC_DISABLE_KEY_OPERATION_COPY 
#define SEC_DISABLE_KEY_OPERATION_ELEMENT_COPY 


/* CSM Key: CsmKey_KeyMCertificate_ADA_L4; Key Element: Crypto_30_vHsm_KeyM_KeyM_Certificate*/
#define SecM_AuthDiag_Certificate_SetValue(keyPtr, keyLength)    SecM_KeyElementSet(0x00000001u, 0x00000C08u, (keyPtr), (keyLength)) 
#define SecM_AuthDiag_Certificate_GetValue(keyPtr, keyLengthPtr) SecM_KeyElementGet(0x00000001u, 0x00000C08u, (keyPtr), (keyLengthPtr)) 

/* CSM Key: CsmKey_RoleFlag; Key Element: Crypto_30_vHsm_LibCv_RoleFlag*/
#define SecM_AuthDiag_SetStatus(keyPtr, keyLength)    SecM_KeyElementSet(0x00000003u, 0x00000001u, (keyPtr), (keyLength)) 
#define SecM_AuthDiag_GetStatus(keyPtr, keyLengthPtr) SecM_KeyElementGet(0x00000003u, 0x00000001u, (keyPtr), (keyLengthPtr)) 

/* CSM Key: CsmKey_KeyMCertificate_ADA_L4; Key Element: Crypto_30_vHsm_KeyM_KeyM_GetStatus*/
#define SecM_AuthDiag_Certificate_SetStatus(keyPtr, keyLength)    SecM_KeyElementSet(0x00000001u, 0x00000C09u, (keyPtr), (keyLength)) 
#define SecM_AuthDiag_Certificate_GetStatus(keyPtr, keyLengthPtr) SecM_KeyElementGet(0x00000001u, 0x00000C09u, (keyPtr), (keyLengthPtr)) 

/* CSM Key: CsmKey_KeyMCertificate_ADA_L4; Key Element: Crypto_30_vHsm_KeyM_KeyM_VerifyCertificate*/
#define SecM_AuthDiag_Certificate_SetVerify(keyPtr, keyLength)    SecM_KeyElementSet(0x00000001u, 0x00000C0Au, (keyPtr), (keyLength)) 
#define SecM_AuthDiag_Certificate_GetVerify(keyPtr, keyLengthPtr) SecM_KeyElementGet(0x00000001u, 0x00000C0Au, (keyPtr), (keyLengthPtr)) 



/* Save/Restore switches */
#define SEC_DISABLE_SAVE_RESTORE_CONTEXT 


/* User Config File Start */
#define SECM_HASH_SIZE 0x20u
/* User Config File End */


#endif /* __SECM_CFG_H__ */

