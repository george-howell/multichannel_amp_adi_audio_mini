/**
 * @file    bm_ma12040p_device.h
 *
 * @brief
 *  
 * @par
 * Created On: 02/07/2022
 * Created By: G. Howell
 */

/*------------------- INCLUDES -----------------------------------*/

#include "bm_ma12040p_device.h"

/*------------------- EXTERN VARIABLES ---------------------------*/
/*------------------- PRIVATE MACROS AND DEFINES -----------------*/
/*------------------- PRIVATE TYPEDEFS ---------------------------*/
/*------------------- STATIC VARIABLES ---------------------------*/
/*------------------- GLOBAL VARIABLES ---------------------------*/
/*------------------- STATIC FUNCTION PROTOTYPES -----------------*/
/*------------------- STATIC FUNCTIONS ---------------------------*/
/*------------------- GLOBAL FUNCTIONS ---------------------------*/

/**
 * @brief Initialises the MA12040P I2C connection
 *
 * @param   ma12040p_config  MA12040P configuration structure
 *
 * @return  MA12040P status
 */
BM_MA12040P_RESULT ma12040p_init(BM_MA12040P_CONFIG *ma12040p_config)
{
	if (twi_initialize(&ma12040p_config->twi, ma12040p_config->i2c_address, TWI_TYPICAL_SCLK0_FREQ, ma12040p_config->device_num) != TWI_SIMPLE_SUCCESS)
	{
		return MA12040P_ERROR;
	}
	twi_set_clock(&ma12040p_config->twi, 100000);

	return MA12040P_SUCCESS;
}

/**
 * @brief Writes a register value to the MA12040P
 *
 * @param   ma12040p_config  MA12040P configuration structure
 * @param   reg_addr  register address
 * @param   reg_value  register value to write
 *
 * @return  MA12040P status
 */
BM_MA12040P_RESULT ma12040p_write_reg(BM_MA12040P_CONFIG *ma12040p_config,
								      uint8_t reg_addr,
									  uint8_t reg_value)
{
	uint8_t data[2];
	data[0] = reg_addr;
	data[1] = reg_value;

	if (TWI_SIMPLE_TIMEOUT == twi_write_block(&ma12040p_config->twi, data, 2))
	{
		return MA12040P_ERROR;
	}

	return MA12040P_SUCCESS;
}

/**
 * @brief Reads a register value from the MA12040P
 *
 * @param   ma12040p_config  MA12040P configuration structure
 *
 * @return  MA12040P status
 */
BM_MA12040P_RESULT ma12040p_read_reg(BM_MA12040P_CONFIG *ma12040p_config,
								      uint8_t reg_addr,
									  uint8_t *reg_value)
{
	if (TWI_SIMPLE_TIMEOUT == twi_write_block(&ma12040p_config->twi, &reg_addr, 1))
	{
		return MA12040P_ERROR;
	}
	if (TWI_SIMPLE_TIMEOUT == twi_read(&ma12040p_config->twi, reg_value))
	{
		return MA12040P_ERROR;
	}

	return MA12040P_SUCCESS;
}
