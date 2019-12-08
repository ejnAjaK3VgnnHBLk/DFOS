#include <bool.h>

int charToInt(char* ch) {
    return (ch - '0');
}

bool isNum(char* ch) {
    return (ch >= 0 && ch <= 9);
}