AS = arm-none-eabi-as
CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0 -mthumb

all: t1.o test.o HW1.elf

t1.o:
	$(AS) -g -mcpu=cortex-m0 -mthumb t1.s -o t1.o

test.o:
	$(CC) $(CFLAGS) test.c -c -o test.o

HW1.elf:
	$(CC) $(CFLAGS) -g --specs=rdimon.specs -lc -lrdimon t1.o test.o -o HW1.elf

test : HW1.elf
	qemu-system-arm  -machine versatilepb -cpu cortex-m3 \
		-nographic -monitor null -serial null	\
		-semihosting -kernel HW1.elf > output.txt
main.s:test.c
	$(CC) -c -S -g -mcpu=cortex-m0 -mthumb test.c -o main.s
