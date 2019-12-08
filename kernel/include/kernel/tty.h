#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <regint.h>

#define VGA_ADDRESS (uint16_t*)0xC03FF000
#define BUFSIZE 2200

#define NULL 0

enum vga_color {
    BLACK, 
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY, 
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

uint16_t vga_entry(unsigned char ch, uint8_t fg, uint8_t bg);
void clear_vga_buffer(uint16_t **buffer, uint8_t fg, uint8_t bg);
void init_vga(uint8_t fg, uint8_t bg);
void charPtr(char ch);
void strPtr(char *str);


#endif
