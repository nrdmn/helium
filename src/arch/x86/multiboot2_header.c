#include <arch/x86/types.h>

struct {
	uint32_t magic;
	uint32_t architecture;
	uint32_t header_length;
	uint32_t checksum;
	struct {
		uint16_t type;
		uint16_t flags;
		uint32_t length;
		uint32_t mbi_tag_types[1];
	} information_request;
	struct {
		uint16_t type;
		uint16_t flags;
		uint32_t length;
	} end_tag __attribute__((aligned(8)));
} multiboot2_header __attribute__((section(".multiboot"), aligned(8))) = {
	.magic = 0xe85250d6,
	.architecture = 0,
	.header_length = sizeof(multiboot2_header),
	.checksum = 0x100000000 - (0xe85250d6 + sizeof(multiboot2_header)),
	.information_request = {
		.type = 1,
		.flags = 1,
		.length = sizeof(multiboot2_header.information_request),
		.mbi_tag_types = {4},
	},
	.end_tag = {
		.type = 0,
		.flags = 0,
		.length = sizeof(multiboot2_header.end_tag),
	},
};
