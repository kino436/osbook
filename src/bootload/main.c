#include "defines.h"
#include "serial.h"
#include "lib.h"

int main(void)
{
	serial_init(SERIAL_DEFAULT_DEVICE); //�V���A���f�o�C�X��������

	puts("Hello World\n");

	while(1)
		;

	return 0;
}
