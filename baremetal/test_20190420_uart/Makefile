CC = arm-linux-gcc
LD = arm-linux-ld
OBJCOPY = arm-linux-objcopy
OBJDUMP = arm-linux-objdump

CFLAGS = -Werror -I.
SFLAGS = -march=armv4

C_SRCS = $(wildcard *.c)
S_SRCS0 = $(wildcard *.s) 
S_SRCS1 = $(wildcard *.S)
OBJS_C = $(patsubst %.c, %.o, $(C_SRCS)) 
OBJS_S0 = $(patsubst %.s, %.o, $(S_SRCS0))
OBJS_S1 = $(patsubst %.S, %.o, $(S_SRCS1))

DEP_FILES := $(patsubst %, .%.d, $(OBJS))
DEP_FILES := $(wildcard $(DEP_FILES))
TARGET = test_$(shell date +"%Y%m%d%H%M%S")

all: $(TARGET)

$(TARGET):$(OBJS_C) $(OBJS_S0) $(OBJS_S1)
	@echo $(TARGET)
	$(LD) -Ttext 0 -o $@.elf $^
	$(OBJCOPY) -O binary -S $@.elf $@.bin
	$(OBJDUMP) -D $@.elf > $@.dis
%.o:%.s
	$(CC) $(SFLAGS) -c -o $@ $<
%.o:%.S
	$(CC) $(SFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $< -MD -MF .$@.d
clean:
	rm *.bin *.o *.elf *.dis

.PHONY:all clean	
