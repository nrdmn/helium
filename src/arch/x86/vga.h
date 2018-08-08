#ifndef VGA_H
#define VGA_H

#include <types.h>

static char *vga_buf;

struct vga_cursor {
	uint8_t x;
	uint8_t y;
	uint8_t color;
};

void vga_clear(void);

void vga_write(char *);

#endif /* VGA_H */
