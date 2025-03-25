# sep4_drivers
This repository contains a collection of drivers designed to to work with the hardware at SEP4 at Software Technology Engineering at VIA. All drivers are located in the lib/drivers directory.


### 1. adxl345.h
This driver interfaces with the ADXL345 chip, a 3-axis accelerometer, that measures up to ±4 g. It can be used to measure the static acceleration of gravity in tilt-sensing applications, as well as dynamic acceleration resulting from motion or shock.

### 2. buttons.h
This driver is designed to control the three buttons located on top of the multifunction shield.

### 3. buzzer.h
Controls the active buzzer positioned on the multifunction shield. 

### 4. dht11.h
The DHT11 is a basic digital temperature and humidity sensor. This driver allows for interfacing with the DHT11 to obtain temperature and humidity readings.

### 5. display.h
This driver controls the four 7-segment displays positioned on top of the multifunction shield. It can be used to display numbers or certain characters.

### 6. hc_sr04.h
The HC-SR04 is an ultrasonic ranging module that provides 2 cm to 400 cm non-contact measurement functionality. This driver facilitates the measurement of distance using ultrasonic waves.

### 7. leds.h
Controls the four LEDs located on top of the multifunction shield. This can be used for indication, signaling, or other visual purposes.

### 8. light.h
This driver controls the photoresistor and is capable of measuring the amount of light in the environment.

### 9. pc_comm.h
Facilitates communication to the PC over USB using UART. 

### 10. periodic_task.h
This driver sets up an interrupt-based service that can call a function at a specified interval. It's useful for tasks that need to be executed periodically without manual intervention.

### 11. pir.h
This driver interfaces with the HC-SR501 is a passive infrared (PIR) motion sensor. 

### 12. servo.h
This driver interfaces with the SG90 servo motor and can set it to a position ranging from 0 to 180 degrees.

### 13. tone.h
This driver can generate tones of specified frequencies, using a passive buzzer. By providing different frequency values, you can play various tones or even simple melodies.

### 14. uart.h
This driver facilitates UART (Universal Asynchronous Receiver-Transmitter) communication. It is utilized by both the pc_comm and wifi drivers to enable data transfer and communication functionalities.

### 15. wifi.h
This driver interfaces with the ESP8266 module, a Wi-Fi microchip with full TCP/IP stack and microcontroller capability. With this driver, you can connect to an Access Point (AP) and establish a TCP connection, and send and receive data through the TCP-connection.
