
CC = arm-linux-gcc
LD = arm-linux-ld
OBJCOPY = arm-linux-objcopy
OBJDUMP = arm-linux-objdump

CFLAGS = -Werror -I.
SFLAGS = -march=armv4

C_SRCS = $(wildcard *.c)
S_SRCS = $(wildcard *.s)
OBJS = $(patsubst %c, %o, $(C_SRCS)) $(patsubst %s, %o, $(S_SRCS))
DEP_FILES := $(patsubst %, .%.d, $(OBJS))
DEP_FILES := $(wildcard $(DEP_FILES))
TARGET = test_$(shell date +"%Y%m%d%H%M%S")

.PHONY:all clean


ifneq ($(DEP_FILES),)
include $(DEP_FILES)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -Ttext 0  -o $@.elf $^
	$(OBJCOPY) -O binary -S $@.elf $@.bin
	$(OBJDUMP) -D $@.elf > $@.dis

%.o:%.s
	$(CC) -c -o $@ $<

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

clean:
	rm -f *.d *.elf *.bin *.o



