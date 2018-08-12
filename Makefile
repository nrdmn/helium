.PHONY: kernel clean qemu-x86_64

ARCH?=x86
export ARCH

ifeq ($(ARCH),x86)
ASFLAGS=--32
CFLAGS=-m32 -nostdlib -nostdinc -fno-asynchronous-unwind-tables -fno-pic
LDFLAGS=-melf_i386
endif
export ASFLAGS
export CFLAGS
export LDFLAGS

kernel:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean

qemu-x86_64: kernel
	qemu-system-x86_64 -curses -kernel src/kernel
