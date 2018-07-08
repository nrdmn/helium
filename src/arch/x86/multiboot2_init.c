#include "vga.h"

void multiboot2_init(void *multiboot2_information)
{
	vga_clear();
	vga_write("Multiboot2 detected!\n");

	main();
}

