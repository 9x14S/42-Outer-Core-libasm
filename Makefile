.PHONY : all re clean fclean main bonus

TARGET      := libasm.a

TESTER      := a.out

CC          := /usr/bin/cc
CFLAGS      := -Wall -Wextra -ggdb3 -O0 -fno-stack-protector

AR          := /usr/bin/ar
ARFLAGS     := rcs

LD          := /usr/bin/ld
AS          := /usr/bin/nasm
ASFLAGS     := -f elf64

MANDATORY_SRCS    := ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s\
                     ft_write.s ft_read.s # main.s
BONUS_SRCS        := ft_list_size.s
OBJS              := $(MANDATORY_SRCS:.s=.o)

ifeq ($(MAKECMDGOALS),bonus)
OBJS += $(BONUS_SRCS:.s=.o)
endif

all bonus: $(TARGET)
$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

main: $(TESTER)
$(TESTER): main.c $(TARGET)
	$(CC) $(CFLAGS) -o $(TESTER) $^

ft_strdup.o: ft_strcpy.o ft_strlen.o ft_strdup.s
%.o: %.s Makefile
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(TARGET) $(TESTER)
re: fclean all
