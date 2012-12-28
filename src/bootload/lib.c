#include "defines.h"
#include "serial.h"
#include "lib.h"

/* 1�������M */
int putc(unsigned char c)
{
	if (c == '\n')
		serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
	return serial_send_byte(SERIAL_DEFAULT_DEVICE, c);
}

/* �����񑗐M */
int puts(unsigned char *str)
{
	while (*str)
		putc(*(str++));
	return 0;
}
