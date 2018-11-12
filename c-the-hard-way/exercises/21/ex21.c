#include <stdio.h>
// header file is located in /usr/include/stdint.h
#include <stdint.h>

int main(int argc, char *argv[])
{
	printf("int8_t size: %d byte(s)\n", sizeof(int8_t));
	printf("int16_t size: %d byte(s)\n", sizeof(int16_t));
	printf("int32_t size: %d byte(s)\n", sizeof(int32_t));
	printf("int64_t size: %d byte(s)\n", sizeof(int64_t));

	printf("int_fast16_t: %d bytes(s)\n", sizeof(int_fast16_t));
	printf("int_fast32_t: %d bytes(s)\n", sizeof(int_fast32_t));
	printf("int_fast64_t: %d bytes(s)\n", sizeof(int_fast64_t));

	return 0;
}
