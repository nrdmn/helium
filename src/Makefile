.PHONY: all clean

export ARCH
export ASFLAGS
export CFLAGS
export LDFLAGS

all: main.o
	$(MAKE) -C arch/$(ARCH)
	$(LD) $(LDFLAGS) -n -o kernel -T arch/$(ARCH)/linker.ld arch/$(ARCH)/*.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -I ../include -c -o main.o main.c

clean:
	$(MAKE) -C arch/$(ARCH) clean
	rm -f *.o kernel
