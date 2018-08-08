.PHONY: all clean

export ARCH
export ASFLAGS
export CFLAGS
export LDFLAGS

object_files := $(patsubst %.S, %.o, $(wildcard *.S)) $(patsubst %.c, %.o, $(wildcard *.c))

all:
	$(MAKE) $(object_files)

%.o: %.S
	$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -D ARCH_TYPES=\"arch/$(ARCH)/types.h\" -I ../../../include -c -o $@ $<

clean:
	rm -f *.o
