#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
#if defined(__is_libk)
    // make real kernel panic lol
    printf("kernel panic: abort()\n");
#else
    printf("abort()\n");

#endif
    while (1) {}
    __buildtin_unreachable();
}