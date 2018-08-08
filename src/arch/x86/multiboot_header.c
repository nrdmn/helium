#include <types.h>

struct {
	uint32_t magic;
	uint32_t flags;
	uint32_t checksum;
} multiboot_header __attribute__((section(".multiboot"), aligned(4))) = {
	.magic = 0x1badb002,
	.flags = 1,
	.checksum = 0x100000000 - (0x1badb002 + 1),
};
