#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <setjmp.h>

#define TEST_NULL "Testing crashes on NULL for: "
#define OK "OK\n"
#define CRASH "CRASH\n"

#define TEST(x) do {\
if (test_crashing_function((void *)&x, #x "\n"))\
	write(1, OK, sizeof(OK) - 1);\
else\
	write(1, CRASH, sizeof(CRASH) - 1);\
} while (0);

jmp_buf	did_crash;

void	segfault_sighandler(int signum)
{
	(void)signum;
	longjmp(did_crash, 1);
}

int	test_crashing_function(void *function, char *function_name)
{
	volatile void *null = NULL;
	write(1, TEST_NULL, sizeof(TEST_NULL) - 1);
	write(1, function_name, __builtin_strlen(function_name));
	if (setjmp(did_crash) == 0)
	{
		volatile size_t whatever = ((size_t (*)(void *))function)((char *)null);
		(void)whatever;
		return 1;
	}
	return 0;
}

int	main(void)
{
	signal(SIGSEGV, segfault_sighandler);
	TEST(strlen);
	return 0;
}
