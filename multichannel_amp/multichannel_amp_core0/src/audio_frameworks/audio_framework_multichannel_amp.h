/**
 * @file    audio_framework_multichannel_amp.h
 *
 * @brief   Description
 *  
 * @par
 * Created On: 02/07/2022
 * Created By: G. Howell
 */

#ifndef __AUDIO_FRAMEWORK_MULTICHANNEL_AMP_H__
#define __AUDIO_FRAMEWORK_MULTICHANNEL_AMP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*------------------- INCLUDES -----------------------------------*/

#include "stdint.h"
#include "drivers/bm_twi_driver/bm_twi.h"
#include "drivers/bm_event_logging_driver/bm_event_logging.h"
#include "drivers/bm_ma12040p_driver/bm_ma12040p_device.h"

/*------------------- MACROS AND DEFINES -------------------------*/

#define AF_I2C_MUX_DEV_ADDR			((uint8_t)0x70)
#define AF_I2C_SPEED				100000


/*------------------- TYPEDEFS -----------------------------------*/

typedef enum
{
	AF_MULTIAMPS_SUCCESS,
	AF_MULTIAMPS_ERROR
} AF_MULTIAMPS_STATUS;

/*------------------- EXPORTED VARIABLES -------------------------*/
/*------------------- GLOBAL FUNCTION PROTOTYPES -----------------*/

AF_MULTIAMPS_STATUS amp_initialise(void);

#ifdef __cplusplus
}
#endif

#endif /* __AUDIO_FRAMEWORK_MULTICHANNEL_AMP_H__ */
