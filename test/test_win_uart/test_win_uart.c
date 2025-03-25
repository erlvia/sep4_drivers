#include "unity.h"
#include "uart.h"
#include "mock_avr_io.h"
#include "../fff.h"

DEFINE_FFF_GLOBALS
FAKE_VOID_FUNC(sei);
FAKE_VOID_FUNC(cli);

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_uart_init0(){
    uart_init(USART_0, 9600, NULL);
    

}

void test_uart_init1(){

    uart_init(USART_1, 9600, NULL);

}

void test_uart_init3(){

    uart_init(USART_3, 9600, NULL);

}



int main(void) {
    UNITY_BEGIN();
  RUN_TEST(test_uart_init0);
  RUN_TEST(test_uart_init1);
  return UNITY_END();
}