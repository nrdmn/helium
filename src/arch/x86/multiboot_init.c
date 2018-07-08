#include "vga.h"

void multiboot_init(void *multiboot_information)
{
	vga_clear();
	vga_write("Multiboot detected!\n");

	main();
}
