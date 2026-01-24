#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define TEST_NULL "Testing crashes on NULL for: "
#define OK "OK\n"
#define CRASH "CRASH\n"

#define TEST(x) do {\
if (test_crashing_function((void *)&x, #x "\n"))\
	write(1, CRASH, sizeof(CRASH) - 1);\
else\
	write(1, OK, sizeof(OK) - 1);\
} while (0);

#define CAST_PTR(x) ((size_t (*)(void *, void *, void *))x)

#define _STRINGIFY(x) #x

#define SYSCALL(syscall, x, y, z, explanation) do {\
	asm(".intel_syntax noprefix;"\
		"mov rax, " #syscall ";"\
		"mov rdi, " #x ";"\
		"mov rsi, " #y ";"\
		"mov rcx, " #z ";"\
		"syscall;"\
		"mov rsi, rax;"\
		".att_syntax;"\
	);\
	printf(explanation ": %ld\n");\
} while (0);

int	test_crashing_function(void *function, char *function_name)
{
	write(1, TEST_NULL, sizeof(TEST_NULL) - 1);
	write(1, function_name, __builtin_strlen(function_name));
	pid_t pid = fork();
	if (pid < 0)
		exit(255);
	if (pid == 0)
	{
		volatile size_t whatever = CAST_PTR(function)(NULL, NULL, NULL);
		(void)whatever;
		exit(0);
	}
	int stat_loc;
	wait(&stat_loc);
	return WIFSIGNALED(stat_loc);
}

int	main(void)
{
	TEST(strlen);
	TEST(strcpy);
	TEST(strcmp);
	TEST(write);
	TEST(read);
	TEST(strdup);

	SYSCALL(1, 1, 0x00, 0xffff, "Syscall write with NULL buffer");
	SYSCALL(1, -1, 0x404000, 0xffff, "Syscall write with bad fd");

	return 0;
}
