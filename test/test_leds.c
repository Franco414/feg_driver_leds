/*=================================================================================================================*/
/*                                                 Includes                                                        */
/*=================================================================================================================*/
#include <stdbool.h>

#include "leds.h"
#include "mock_ledsError.h"
#include "unity.h"

/*=================================================================================================================*/
/*                                             Private Variables                                                   */
/*=================================================================================================================*/
uint16_t leds2Test;

/*=================================================================================================================*/
/*                                      Public Funtions - setUP ,  tearDown                                        */
/*=================================================================================================================*/
void setUp(void) { LedsInit(&leds2Test); }
void tearDown(void) {}

/*=================================================================================================================*/
/*                                            Public Test Funtions                                                 */
/*=================================================================================================================*/
void test_LedsOffAfterCreate(void) {
  uint16_t leds2Test = 0xFFFF;
  LedsInit(&leds2Test);
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds2Test);
}

void test_turn_on_led(void) {
  const int led = 2;
  LedsInit(&leds2Test);
  LedsTurnOn(led);
  TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), leds2Test);
}

void test_turn_off_led(void) {
  const int led = 2;
  LedsInit(&leds2Test);
  LedsTurnOn(led);
  LedsTurnOff(led);
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds2Test);
}

void test_turn_on_all_leds(void) {
  LedsTurnOnAll();
  TEST_ASSERT_EQUAL_HEX16(0xFFFF, leds2Test);
}

void test_turn_off_all_leds(void) {
  LedsTurnOnAll();
  LedsTurnOffAll();
  TEST_ASSERT_EQUAL_HEX16(0x0000, leds2Test);
}

void test_turnOn_after_turnOff_manyLeds(void) {
  const int led = 2;
  LedsTurnOn(led);
  LedsTurnOn(5);
  LedsTurnOff(5);
  TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), leds2Test);
}

void test_led_is_on(void) {
  const int led = 3;
  LedsTurnOn(led);
  bool test_state_led = LedsStatusGet(led);
  TEST_ASSERT_TRUE(test_state_led);
}

void test_led_is_off(void) {
  const int led = 3;
  LedsTurnOn(led);
  LedsTurnOff(led);
  bool test_state_led = LedsStatusGet(led);
  TEST_ASSERT_FALSE(test_state_led);
}

void test_invalid_index(void) {
  ledsError_messageTriggering_Expect(NUM_LED_INVALID, "Turn on leds error:LED's Number invalid\n");
  LedsTurnOn(17);
  ledsError_messageTriggering_Expect(NUM_LED_INVALID, "Turn on leds error:LED's Number invalid\n");
  LedsTurnOn(0);
  ledsError_messageTriggering_Expect(NUM_LED_INVALID, "Turn off leds error:LED's Number invalid\n");
  LedsTurnOff(21);
  ledsError_messageTriggering_Expect(NUM_LED_INVALID, "Turn off leds error:LED's Number invalid\n");
  LedsTurnOff(0);
}