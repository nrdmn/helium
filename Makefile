.PHONY: kernel clean

ARCH?=x86
export ARCH

ifeq ($(ARCH),x86)
ASFLAGS=--32
CFLAGS=-m32
LDFLAGS=-melf_i386
endif
export ASFLAGS
export CFLAGS
export LDFLAGS

kernel:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean
