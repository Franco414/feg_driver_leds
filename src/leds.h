#ifndef _LEDS_H_
#define _LEDS_H_
/*=================================================================================================================*/
/*                                                 Includes                                                        */
/*=================================================================================================================*/
#include <stdbool.h>
#include <stdint.h>

/*=================================================================================================================*/
/*                                              Public Funtions                                                    */
/*=================================================================================================================*/
/**
 * @brief Function to initialize the LEDs of a port defined by its address.
 * 
 * @param address Pointer referenced to the address of the led port to be handled with the driver. 
 */
void LedsInit(uint16_t *address);
/**
 * @brief Function to turn on a specific led of the controlled port by driver.
 * 
 * @param led variable that contains the number of LEDs to turn on.
 */
void LedsTurnOn(int led);
/**
 * @brief Function to turn off a specific led of the controlled port by driver.
 * 
 * @param led variable that contains the number of LEDs to turn off.
 */
void LedsTurnOff(int led);
/**
 * @brief Function to get the status of a certain led, it included in the port controlled by the driver
 * 
 * @param led variable that contains the number of LEDs to get its state.
 * @return true if the led is on.
 * @return false if the led is off.
 */
bool LedsStatusGet(int led);
/**
 * @brief Function to turn on all the LEDs of a certain port
 * 
 */
void LedsTurnOnAll();
/**
 * @brief Function to turn off all the LEDs of a certain port
 * 
 */
void LedsTurnOffAll();

#endif