#include "wifi.h"
#include "uart.h"
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#define MAX_STRING_LENGTH 100

static uint8_t _index = 0;
static uint8_t _console_receive_buff[MAX_STRING_LENGTH] = {0};
static bool _console_string_received = false;
static char _tcp_receive_buff[MAX_STRING_LENGTH] = {0};
static bool _tcp_string_received = false;

// This is a callback function. Execution time must be short!
void console_rx(uint8_t _rx)
{
    uart_send_blocking(USART_0, _rx);   // Echo (for demo purposes)
    if(('\r' != _rx) && ('\n' != _rx))
    {
        if(_index < 100-1)
        {
            _console_receive_buff[_index++] = _rx;
        }
    }
    else
    {
        _console_receive_buff[_index] = '\0';
        _index = 0;
        _console_string_received = true;
        uart_send_blocking(USART_0, '\n');   // Echo (for demo purposes)
    }
}

// This is a callback function. Execution time must be short!
void tcp_rx()
{
    uint8_t _index;
    _index = strlen(_tcp_receive_buff);
    _tcp_receive_buff[_index] = '\r';
    _tcp_receive_buff[_index+1] = '\n';
    _tcp_receive_buff[_index+2] = '\0';
    _tcp_string_received = true;
}

int main()
{
    char welcome_text[] = "Welcome from SEP4 IoT hardware!\n";
    char prompt_text[] = "Type text to send: ";

    uart_init(USART_0, 9600, console_rx);
    wifi_init();

    sei();

    wifi_command_join_AP("Erlands SEP4", "ViaUC1234");
    wifi_command_create_TCP_connection("192.168.137.102", 23, tcp_rx, _tcp_receive_buff);
    wifi_command_TCP_transmit((uint8_t*)welcome_text, strlen(welcome_text) );
    uart_send_string_blocking(USART_0, prompt_text);

    while(1)
    {
        if(_console_string_received)
        {
            wifi_command_TCP_transmit(_console_receive_buff, strlen((char*)_console_receive_buff) );
            _console_string_received = false;
        }
        if(_tcp_string_received)
        {
            uart_send_string_blocking(USART_0, _tcp_receive_buff);
            _tcp_string_received = false;
        }
    }
    return 0;
}