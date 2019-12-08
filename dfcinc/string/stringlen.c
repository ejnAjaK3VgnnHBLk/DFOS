#include <string.h>

size_t stringlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
