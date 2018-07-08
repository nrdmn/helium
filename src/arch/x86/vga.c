#include "vga.h"

static void memcpy(char *dst, const char *src, size_t n)
{
	while (n-- > 0)
		dst[n] = src[n];
}

static void memset(char *dst, char c, size_t n)
{
	while (n-- > 0)
		dst[n] = c;
}

static char *vga_buf = 0xb8000;

static struct vga_cursor vga_cursor;

void vga_clear()
{
	asm(
		"pushf                  \n"
		"push %eax              \n"
		"push %edx              \n"
		"movw $0x3d4, %dx       \n"
		"movb $0xa, %al         \n"
		"outb %al, %dx          \n"
		"incw %dx               \n"
		"movb $0x20, %al        \n"
		"outb %al, %dx          \n"
		"pop %edx               \n"
		"pop %eax               \n"
		"popf                   \n"
	); /* disable the cursor */
	for (uint16_t i = 0; i < 80*25*2;) {
		vga_buf[i++] = 0;
		vga_buf[i++] = 0;
	}
	vga_cursor.x = 0;
	vga_cursor.y = 0;
	vga_cursor.color = 0x7;
}

void vga_write(char *data)
{
	size_t i = 0;
	while (data[i] != 0) {
		if (data[i] != '\n') {
			vga_buf[vga_cursor.x*2+vga_cursor.y*80*2] = data[i];
			vga_buf[vga_cursor.x*2+vga_cursor.y*80*2+1] = vga_cursor.color;

			if (vga_cursor.x == 79) {
				vga_cursor.x = 0;
				vga_cursor.y++;
			} else {
				vga_cursor.x++;
			}
		} else {
			vga_cursor.y += 1;
			vga_cursor.x = 0;
		}

		if (vga_cursor.y == 25) {
			vga_cursor.y = 24;

			for (char j = 0; j < 25; j++) {
				memcpy(vga_buf+j*160, vga_buf+(j+1)*160, 160);
			}
		}

		i++;
	}
}
