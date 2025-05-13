#include "unity.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "PC_Comm.h"
#include "light.h"
#include "soil.h"



void setUp()
{
}

void tearDown()
{}

void test_light_sensor()
{
    light_init();

    uint16_t light = light_read();
    char message[1024];
    sprintf(message, "INFO! photo_resistor measurement= %d       :1:_:PASS\n", light);
    TEST_MESSAGE(message); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n"); // no : in the message
}

void test_soil_sensor()
{
    soil_init();
    _delay_ms(100);
 
    uint16_t sm = soil_read();
    char message[1024];
    sprintf(message, "INFO! soil moisture measurement= %d       :1:_:PASS\n", sm);
    TEST_MESSAGE(message);
}

void test_water_pump()
{
    TEST_MESSAGE("INFO! Water pump should run for 3 seconds       :1:_:PASS\n");
    DDRC |= (1<<PC7);
    PORTC |= (1<<PC7);
    _delay_ms(3000);
    PORTC &= ~(1<<PC7);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_light_sensor);
    RUN_TEST(test_soil_sensor);
    RUN_TEST(test_water_pump);
    return UNITY_END();
}