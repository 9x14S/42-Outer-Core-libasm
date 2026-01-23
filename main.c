#include <string.h>
#include <stdio.h>

#include "libasm.h"

#define TEST(x, y) do {\
long x_val = (long)x;\
long y_val = (long)y;\
printf("TESTING: " #x " and " #y "\nRESULT: (%ld), (%ld)\nGRADE:%s\n",\
x_val, y_val, x_val == y_val ? "PASS" : "FAIL");\
} while (0)

int main(void)
{
	// strlen tests
	TEST(ft_strlen("aaa"), strlen("aaa"));
	TEST(ft_strlen(""), strlen(""));
	TEST(ft_strlen("aaaaaaaaaaaaaaaaaaaaaa"), strlen("aaaaaaaaaaaaaaaaaaaaaa"));

	// strcmp tests
	TEST(ft_strcmp("", ""), strcmp("", ""));
	TEST(ft_strcmp("aaa", "aaa"), strcmp("aaa", "aaa"));
	TEST(ft_strcmp("aab", "aaa"), strcmp("aab", "aaa"));
	TEST(ft_strcmp("bab", "aaa"), strcmp("bab", "aaa"));

	return (0);
}
