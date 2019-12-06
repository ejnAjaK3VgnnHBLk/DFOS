#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/paging.h>

void kernel_main(void) {
	paging_init();
	terminal_initialize();
	printf("Hello, kernel World!\n");
}
