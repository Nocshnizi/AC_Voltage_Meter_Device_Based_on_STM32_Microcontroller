/*
 * myTypes.h
 *
 *  Created on: 13 марта 2017 г.
 *      Author: Maxim
 */

#ifndef MYTYPES_H_
#define MYTYPES_H_

#define UART_BUFF_SIZE 255

// Structure to store global flags and LEDs pulse widths
typedef struct
{
  unsigned buton_pressed_once  		:1;
  unsigned buton_pressed_again 		:1;
  unsigned button_enable					:1;
  unsigned uart_transfer_complete :1;
  uint8_t  pw[3];
} myMessages_t;

// Flag that indicates button state
typedef struct
{
  unsigned pressed        :1;
} buttonPinState_t;

// Pointer to the functions that realize different commands coming from UART
typedef  void (*command_ptr)(uint8_t**, uint8_t*);

// Structure that realize linear and circular buffer for the UART RX and TX data
typedef struct
{
	uint8_t buffer[UART_BUFF_SIZE];
	uint8_t *message_begin;
	uint8_t *message_end;
}uartBuffer_t;


#endif /* MYTYPES_H_ */
