.PHONY : all re clean fclean main

TARGET      := libasm.a

TESTER      := a.out

CC          := /usr/bin/cc
CFLAGS      := -Wall -Wextra -ggdb3 -O0

AR          := /usr/bin/ar
ARFLAGS     := rcs

LD          := /usr/bin/ld
AS          := /usr/bin/nasm
ASFLAGS     := -f elf64

ASM_SRCS    := ft_strlen.s ft_strcpy.s ft_strcmp.s # ft_write.s ft_read.s\
			   ft_strdup.s main.s
OBJS        := $(ASM_SRCS:.s=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

main: $(TESTER)
$(TESTER): main.c $(TARGET)
	$(CC) $(CFLAGS) -o $(TESTER) $^

%.o: %.s Makefile
	$(AS) $(ASFLAGS) -o $@ $<
