ERASE_FCT=rm -f

CROSS_COMPILE=arm-elf-

OUTFILE=wynik.elf


INCL=./include

OPTIM=

AS=$(CROSS_COMPILE)gcc
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)gcc
NM= $(CROSS_COMPILE)nm
SIZE=$(CROSS_COMPILE)size
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump
CCFLAGS=-g -mcpu=arm9 $(OPTIM) -Wall -I$(INCL)
ASFLAGS=-D__ASSEMBLY__ -g -mcpu=arm9 -c $(OPTIM) -Wall -I$(INCL)

LDFLAGS+=-nostartfiles 
LDFLAGS+=-lc -lgcc
LDFLAGS+=-T elf32-littlearm.lds
OBJS=cstartup.o
OBJS+= lowlevel.o first.o dbg_print.o


rebuild: all

all: $(OUTFILE)

$(OUTFILE): $(OBJS)
	$(LD) $(LDFLAGS) -g -Ttext 0x20000000 -Tdata 0x300000 -n -o $(OUTFILE) $(OBJS)


lowlevel.o: lowlevel.c
	$(CC) -c $(CCFLAGS) lowlevel.c -o lowlevel.o

dbg_print.o: dbg_print.c
	$(CC) -c $(CCFLAGS) dbg_print.c -o dbg_print.o

cstartup.o:  cstartup.S
	$(AS) $(ASFLAGS) cstartup.S -o cstartup.o

first.o: first.S 
	$(AS) $(ASFLAGS) first.S -o first.o

clean:
	$(ERASE_FCT) *.o *.bin *.elf *.map
