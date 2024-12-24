#include <stdint.h>

// Define VGA text mode colors for output
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x0F

// VGA text buffer
char* video = (char*)VGA_MEMORY;

void write_char(char c, int x, int y, uint8_t color) {
    video[2 * (y * VGA_WIDTH + x)] = c;
    video[2 * (y * VGA_WIDTH + x) + 1] = color;
}

void print(const char* str) {
    int x = 0;
    int y = 0;
    while (*str) {
        if (*str == '\n') {
            x = 0;
            y++;
        } else {
            write_char(*str, x, y, WHITE_ON_BLACK);
            x++;
        }
        str++;
    }
}

// Kernel entry point
extern "C" void kernel_main() {
    print("Hello, OS World!");
    while (1); // Infinite loop to halt execution
}
