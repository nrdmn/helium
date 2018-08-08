ENTRY(_start)

SECTIONS {
	vga_buf = 0xb8000;

	. = 1M;

	.multiboot ALIGN (4K) :
	{
		*(.multiboot)
		*(.multiboot2)
	}

	.text ALIGN (4K) :
	{
		*(.text)
	}

	.rodata ALIGN (4K) :
	{
		*(.rodata)
	}

	.bss ALIGN (4K) :
	{
		*(.bss)
	}

	/DISCARD/ :
	{
		*(.comment)
	}
}
