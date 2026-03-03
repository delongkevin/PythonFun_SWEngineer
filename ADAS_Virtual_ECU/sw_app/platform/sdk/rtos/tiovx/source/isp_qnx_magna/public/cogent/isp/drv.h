/*!
 *  @file       drv.h
 *  @brief      V3M driver
 *  @date       2016/Dec/10 latest update
 *  @author     Kaneko
 *  @version    0.01
 *  @par        history
 *  @note       
 */
#ifndef DRV_H
#define DRV_H

#include <stdint.h>
#include <stdbool.h>

/* Common type definition for drivers */
typedef bool                BOOL;
typedef int8_t              INT8;
typedef int16_t             INT16;
typedef int32_t             INT32;
typedef int64_t             INT64;
typedef uint8_t             UINT8;
typedef uint16_t            UINT16;
typedef uint32_t            UINT32;
typedef uint64_t            UINT64;
typedef uintptr_t			UINTPTR_T;

/* TODO: FLOAT should be deleted */
typedef float               FLOAT;

/* Boolean value */
#define drv_FALSE           ((BOOL)false)
#define drv_TRUE            ((BOOL)true)

/* Return code of API */
#define drv_OK                                  (0U)    /* API completed without any error. */
#define drv_FAIL                                (1U)    /* Failed. */
#define drv_INVALID_SPI                         (2U)    /* Specified SPI number is not available. */
#define drv_NULL_FUNC                           (3U)    /* Callback function is not specified. */
#define drv_INVALID_TARGET                      (4U)    /* Invalid target CPU  for the interrupt was specified. */
#define drv_INVALID_PRIO                        (5U)    /* Invalid priority  for the interrupt is specified. */
#define drv_IS_ENABLED                          (6U)    /* Specified SPI number was already enabled. */
#define drv_NOT_SETUP_SPI                       (7U)    /* Specified SPI number is not registered. */
#define drv_COMSTART                            (8U)    /* Communication has been started. */
#define drv_COMNOTSTART                         (9U)    /* Communication has not been started. */

#define drv_ERR_PARAM                           (101U)  /* Parameter error */
#define drv_ERR_NOT_INITIALIZED                 (102U)  /* API called before the driver initialized. */
#define drv_ERR_NOT_OPENED                      (103U)  /* API called before the driver opened. */
#define drv_ERR_OPENED                          (104U)
#define drv_ERR_ALLREADY_OPENED                 (105U)  /* The driver re-opened while it is already opened */
#define drv_ERR_ALREADY_RUNNING                 (106U)  /* The driver re-run while it is already running */
#define drv_ERR_DETECTED_UNEXPECTED_INTERRUPT   (107U)  /* Unexpected interrupt has been detected */
#define drv_ERR_AL_DETECTED                     (108U)  /* Arbitration lost in I2C has occurred */
#define drv_ERR_NACK_RECEIVED                   (109U)  /* NACK in I2C has occurred */
#define drv_ERR_UNUSABLE_CH                     (110U)  /* Invalid channel was specified */
#define drv_ERR_NOT_RUNNING_YET                 (111U)  /* API was called before the driver had been running. */
#define drv_ERR_CLOCK_START                     (112U)  /* Clock supply could not be started. */
#define drv_ERR_CLOCK_STOP                      (113U)  /* Clock supply could not be stopped. */
#define drv_ERR_ALREADY_INITIALIZED             (114U)  /* Initialization API called while the driver is already initialized */
#define drv_ERR_NOT_RUNNING                     (115U)  /* Not running before */
#define drv_ERR_CANNOT_ENABLE_INTERRUPT         (116U)
#define drv_ERR_OS_SEMAPHORE                    (117U)  /* Detected semaphore error from OS */
#define drv_ERR_RUNNING                         (118U)  /* Running before */
#define drv_ERR_INTERNAL                        (199U)

#define drv_SDMAC_CH_INVALID                    (301U)  /* Invalid channel was specified. */
#define drv_SDMAC_CH_BUSY                       (302U)  /* Specified channel is used. */
#define drv_SDMAC_CH_NO_FREE                    (303U)  /* No allocation channel. */
#define drv_SDMAC_DESC_NO_FREE                  (304U)  /* Descriptor memory could not be allocated. */
#define drv_SDMAC_ADDRESS_INVALID               (305U)  /* Specified address could not be found from DDRM table. */
#define drv_SDMAC_NOT_STOPPED                   (306U)  /* Not stoprd SDMAC */

#endif  /* DRV_H */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/ADAS2.0/lib/3rdparty/renesas/isp/public/renesas/drv.h $ $Rev: 873044 $")
#endif
