ENTRY(_start)

SECTIONS {
	. = 1M;

	.multiboot2 ALIGN (4K) :
	{
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
}
