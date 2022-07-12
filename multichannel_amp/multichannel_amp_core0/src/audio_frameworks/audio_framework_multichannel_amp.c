/**
 * @file    audio_framework_multichannel_amp.c
 *
 * @brief
 *  
 * @par
 * Created On: 10/07/2022
 * Created By: G. Howell
 */

/*------------------- INCLUDES -----------------------------------*/

#include "audio_framework_multichannel_amp.h"

/*------------------- EXTERN VARIABLES ---------------------------*/
/*------------------- PRIVATE MACROS AND DEFINES -----------------*/
/*------------------- PRIVATE TYPEDEFS ---------------------------*/
/*------------------- STATIC VARIABLES ---------------------------*/

// I2C configuration
static AF_MULTIAMPS_I2C_CONFIG I2C_Config =
{
	.device_num = TWI2,
	.i2c_address = AF_I2C_MUX_DEV_ADDR
};

/*------------------- GLOBAL VARIABLES ---------------------------*/
/*------------------- STATIC FUNCTION PROTOTYPES -----------------*/
/*------------------- STATIC FUNCTIONS ---------------------------*/

static AF_MULTIAMPS_STATUS i2c_init(AF_MULTIAMPS_I2C_CONFIG *i2c_config);

/*------------------- GLOBAL FUNCTIONS ---------------------------*/

/**
 * @brief Initialises the MA12040P I2C connection
 *
 * @param   ma12040p_config  MA12040P configuration structure
 *
 * @return  MA12040P status
 */
AF_MULTIAMPS_STATUS amp_initialise(void)
{
	char message[128];

	// set the I2C port with the device address of the I2C mux
	if (i2c_init(&I2C_Config) != AF_MULTIAMPS_SUCCESS)
	{
		log_event(EVENT_INFO, "I2C Setup Failure");
	} else
	{
		log_event(EVENT_INFO, "I2C Setup Success");
	}
	sprintf(message, "I2C Config, Bus: %d, Addr: 0x%.2x, Speed: %'.3f KHz",
			I2C_Config.device_num, I2C_Config.i2c_address, (double)AF_I2C_SPEED / 1000.0);
	log_event(EVENT_INFO, message);

	// set the I2C mux to bus 0
	if (TWI_SIMPLE_TIMEOUT == twi_write_block(&I2C_Config->twi, 0x01, 1))
	{
		return AF_MULTIAMPS_ERROR;
	}

	// check if MA12040P devices are detected
	twi_set_temporary_address(&I2C_Config->twi, MA12040P_DEVADDR_1);
	BM_MA12040P_CONFIG *ma12040p_config = I2C_Config
	BM_MA12040P_RESULT ma12040p_read_reg(BM_MA12040P_CONFIG *ma12040p_config,
									      uint8_t reg_addr,
										  uint8_t *reg_value);

	// set the I2C mux to bus 1

	// check if MA12040P devices are detected

	return AF_MULTIAMPS_SUCCESS;
}

/**
 * @brief Initialises the I2C connection
 *
 * @param   i2c_config  I2C configuration structure
 *
 * @return  framework status
 */
static AF_MULTIAMPS_STATUS i2c_init(AF_MULTIAMPS_I2C_CONFIG *i2c_config)
{
	if (twi_initialize(&i2c_config->twi, i2c_config->i2c_address, TWI_TYPICAL_SCLK0_FREQ, i2c_config->device_num) != TWI_SIMPLE_SUCCESS)
	{
		return AF_MULTIAMPS_ERROR;
	}
	twi_set_clock(&i2c_config->twi, AF_I2C_SPEED);

	return AF_MULTIAMPS_SUCCESS;
}
