#include <stdio.h>
#include <stdint.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	printf("Hello, kernel World!\n");
	uint32_t bob = 322;
	printf("Hello this is bob:");
	printf(bob);
}
