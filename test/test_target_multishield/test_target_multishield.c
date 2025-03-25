
#include "unity.h"
#include "buttons.h"
#include <util/delay.h>
#include "pc_comm.h"
#include <avr/io.h>
#include "buzzer.h"
#include "display.h"
#include "servo.h"
#include "leds.h"

void setUp(void)
{
    buttons_init();
}

void tearDown(void)
{
}

void test_button_Not_pressed()
{
    // pc_comm_init(115200, NULL);
    // pc_comm_send_string_blocking("Press button 1! \n\n");
    _delay_ms(1000);

    TEST_ASSERT_EQUAL(0, buttons_1_pressed());
    TEST_ASSERT_EQUAL(0, buttons_2_pressed());
    TEST_ASSERT_EQUAL(0, buttons_3_pressed());
}

void test_display()
{
    display_init();
    _delay_ms(1000);
    for (int16_t i = -999; i < 9999; i++)
    {
        display_int(i);
        _delay_us(400);
    }

    TEST_ASSERT_EQUAL(1, 1);
}

void test_button_pressed()
{
    leds_init();
    // pc_comm_init(115200, NULL);
    // pc_comm_send_string_blocking("Press button 1! \n\n");
    buzzer_beep();
    leds_turnOn(1);
    _delay_ms(200);
    buzzer_beep();
    leds_turnOff(1);
    leds_turnOn(2);
    _delay_ms(200);
    buzzer_beep();
    leds_turnOff(2);
    leds_turnOn(3);
    _delay_ms(200);
    buzzer_beep();
    leds_turnOff(3);
    leds_turnOn(4);
    TEST_ASSERT_EQUAL(1, buttons_1_pressed());
    TEST_ASSERT_EQUAL(1, buttons_2_pressed());
    TEST_ASSERT_EQUAL(1, buttons_3_pressed());
}

void test_servo(){
     TEST_MESSAGE("INFO! the servo should go to 0deg      :1:_:PASS\n");
     servo(0);
    TEST_MESSAGE("INFO! the servo should go to 90deg      :1:_:PASS\n");
    servo(90);
        TEST_MESSAGE("INFO! the servo should go to 180deg      :1:_:PASS\n");
    servo(180);


TEST_ASSERT_TRUE(1);
}

int main(void)
{
    UNITY_BEGIN();
    //_delay_ms(4000);

    RUN_TEST(test_button_Not_pressed);
    TEST_MESSAGE("INFO!!!! When_the displayed_is_finished (reaching 9999), all 3 buttons should be pressed! :1:_:PASS\n"); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n");
    RUN_TEST(test_display);
    RUN_TEST(test_button_pressed);

    RUN_TEST(test_servo);

    return UNITY_END();
}