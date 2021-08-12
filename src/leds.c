/*=================================================================================================================*/
/*                                                 Includes                                                        */
/*=================================================================================================================*/
#include "leds.h"

#include <stdbool.h>

#include "ledsError.h"

/*=================================================================================================================*/
/*                                             Macros Definitions                                                  */
/*=================================================================================================================*/
#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_INDEX_OFFSET 1
#define LEDS_INDEX_START 1
#define LEDS_INDEX_MAX 16

/*=================================================================================================================*/
/*                                                 Includes                                                        */
/*=================================================================================================================*/
static uint16_t *ledsPort;

/*=================================================================================================================*/
/*                                              Private Functions                                                  */
/*=================================================================================================================*/
static int LedsIndexGet(int led) { return (LEDS_INDEX_START << (led - LEDS_INDEX_OFFSET)); }

static bool LedsCheckIndex(int led) { return ((led >= LEDS_INDEX_START) && (led <= LEDS_INDEX_MAX)); }

/*=================================================================================================================*/
/*                                              Public Functions                                                   */
/*=================================================================================================================*/
void LedsInit(uint16_t *ledsAddr) {
  ledsPort = ledsAddr;
  *ledsPort = LEDS_ALL_OFF;
}

void LedsTurnOn(int led) {
  if (LedsCheckIndex(led))
    *ledsPort |= LedsIndexGet(led);
  else
    ledsError_messageTriggering(NUM_LED_INVALID, "Turn on leds error:LED's Number invalid\n");
}

void LedsTurnOff(int led) {
  if (LedsCheckIndex(led))
    *ledsPort &= ~LedsIndexGet(led);
  else
    ledsError_messageTriggering(NUM_LED_INVALID, "Turn off leds error:LED's Number invalid\n");
}

void LedsTurnOnAll() { *ledsPort = LEDS_ALL_ON; }

void LedsTurnOffAll() { *ledsPort = LEDS_ALL_OFF; }

// standar formateo llvm

bool LedsStatusGet(int led) {
  bool ret;
  return ret = (*ledsPort & (LEDS_INDEX_START << --led)) > 0 ? true : false;
}