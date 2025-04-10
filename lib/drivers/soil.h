/**
* @file soil.h
* @brief Driver for Capacitive Soil Moisture Sensor v1.2
*
* @date 09-04-2025
* @author Erland Larsen, VIA University College
*
*/
#pragma once
#include <stdint.h>

#define SOIL_PIN    PK0
#define SOIL_ADC_CHANNEL    ADC8D


/**
 * @brief Initialize ADC for Soil Moisture sensor
 *
 * This function initializes the ADC to read values from the Soil Moisture sensor
 * connected to pin SOIL_PIN.
 */
void soil_init();

/**
 * @brief Read value from Soil Moisture sensor
 *
 * This function reads the ADC values from the Soil Moisture sensor
 * connected to pin SOIL_PIN.
 * 
 * @return 10-bit ADC value read from the Soil Moisture sensor
 */
uint16_t soil_read();