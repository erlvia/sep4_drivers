#include "wifi.h"
#include "uart.h"
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <avr/interrupt.h>

static char _buff[100];
static uint8_t _index = 0;
static bool _done = false;
void console_rx(uint8_t _rx)
{
    uart_send_blocking(USART_0, _rx);
    if(('\r' != _rx) && ('\n' != _rx))
    {
        if(_index < 100-1)
        {
            _buff[_index++] = _rx;
        }
    }
    else
    {
        _buff[_index] = '\0';
        _index = 0;
        _done = true;
        uart_send_blocking(USART_0, '\n');

        // uart_send_string_blocking(USART_0, _buff);

    }
}

int main()
{
    char welcome_text[] = "Welcome to Erland's repeater!\n";
    char prompt_text[] = "Type text to send: ";
    char _buff[100];

    uart_init(USART_0, 9600, console_rx);
    wifi_init();

    sei();

    wifi_command_join_AP("Erland's Galaxy S22", "mtkp8493");
    wifi_command_create_TCP_connection("192.168.39.188", 23, NULL, NULL);
    wifi_command_TCP_transmit((uint8_t*)welcome_text, strlen(welcome_text) );
    uart_send_string_blocking(USART_0, prompt_text);

    while(1)
    {
        if(_done)
        {
            wifi_command_TCP_transmit((uint8_t*)_buff, strlen(_buff) );
            _done = false;
            uart_send_string_blocking(USART_0, prompt_text);
        }
    }
    return 0;
}