#include <tty.h>
#include <regint.h>
#include <string.h>
#include <number.h>

uint32 vga_index;
static uint32 next_line_index = 1;
uint8_t g_fg = WHITE, g_bg = BLUE;


uint16_t vga_entry(unsigned char ch, uint8_t fg, uint8_t bg) {
    uint16_t ax = 0;
    uint8_t ah = 0, al = 0;

    ah = bg;
    ah <<= 4;
    ah |= fg;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
};

void clear_vga_buffer(uint16_t **buffer, uint8_t fg, uint8_t bg) {
    for (uint32 i = 0; i < BUFSIZE; i++) {
        (*buffer)[i] = vga_entry(NULL, fg, bg);;
    }
    next_line_index = 1;
    vga_index = 0;
}

// Start VGA buffer
void init_vga(uint8_t fg, uint8_t bg) {
    vga_buffer = (uint16_t*)VGA_ADDRESSES;
    clear_vga_buffer(&vga_buffer, fg, bg);
    g_fg = fg;
    g_bg = bg;
}

// Increase vga_inde xby width of row(80)
void newline() {
    // Check if end of screen
    if(next_line_index >= 55){
        next_line_index = 0;
        clear_vga_buffer(&vga_buffer, g_gf, g_bg);
    }
    vga_index = 80*next_line_index;
    next_line_index++;
}

void charPtr(char ch) {
    vga_buffer[vga_index] = vga_entry(ch, g_fg, g_bg);
    vga_index++;
}

// We dont need to remove past here
void strPtr(char *str) {
	uint32_t index = 0;
	while(str[index]) { 
		// We use a while loop so that we don't have
		// to use a funciton to find the length of the
		// string in oder to use a for loop. 

		// Check for various special characters
		if (str[index] == '\n') {
			newline();
		} if (isNum(str[index]) == true) {
			charPtr(charToInt(str[index]));
		} else {
			charPtr(str[index]);
		}

		index++;
	}
}
