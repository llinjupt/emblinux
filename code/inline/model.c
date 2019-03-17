#include <stdio.h>

int main()
{
	/*__asm __ ("instruction
           ...
           instruction");   //Linux gccÖĞÖ§³Ö
	*/
	int input = 1, output = 0;
	asm("mov %0, %1" : "=r" (output) : "r" (&input) : "memory");
	printf("input:%d, output:%d\n", input, output);

	return 0;
}
