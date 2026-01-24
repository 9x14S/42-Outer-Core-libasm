#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libasm.h"

#define TEST(x, y) do {\
long x_val = (long)x;\
long y_val = (long)y;\
printf("TESTING: " #x " and " #y "\nRESULT: (%ld), (%ld)\nGRADE:%s\n",\
x_val, y_val, x_val == y_val ? "PASS" : "FAIL");\
} while (0)

#define TEST_CMP(x, y) do {\
long x_val = (long)x;\
long y_val = (long)y;\
printf("TESTING: " #x " and " #y "\nGRADE:%s\n",\
strcmp((char *)x_val, (char *)y_val) == 0 ? "PASS" : "FAIL");\
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

	char	test1[] = "aaa";
	char	test2[] = "aaa";

	// strcpy tests
	TEST_CMP(ft_strcpy(test1, "ccc"), strcpy(test2, "ccc"));
	TEST_CMP(ft_strcpy(test1, "c"), strcpy(test2, "c"));
	TEST_CMP(ft_strcpy(test1, ""), strcpy(test2, ""));

	// strdup tests
	TEST_CMP(ft_strdup("aaaaaaaaaaaaa"), strdup("aaaaaaaaaaaaa"));

	errno = 0;
	ft_write(1, NULL, 0xffff);
	printf("ft_write errno = %d\n", errno);
	errno = 0;
	write(1, NULL, 0xffff);
	printf("write errno    = %d\n", errno);

	errno = 0;
	ft_write(-1, &main, 0xffff);
	printf("ft_write errno = %d\n", errno);
	errno = 0;
	write(-1, &main, 0xffff);
	printf("write errno    = %d\n", errno);

	errno = 0;
	ft_write(-1, NULL, 0xffff);
	printf("ft_write errno = %d\n", errno);
	errno = 0;
	write(-1, NULL, 0xffff);
	printf("write errno    = %d\n", errno);

	#define WHATEVER "TITS\n"
	errno = 0;
	ft_write(1, WHATEVER, sizeof(WHATEVER));
	printf("ft_write errno = %d\n", errno);
	errno = 0;
	write(1, WHATEVER, sizeof(WHATEVER));
	printf("write errno    = %d\n", errno);


	errno = 0;
	ft_read(1, NULL, 0xffff);
	printf("ft_read errno = %d\n", errno);
	errno = 0;
	read(1, NULL, 0xffff);
	printf("read errno    = %d\n", errno);

	errno = 0;
	ft_read(-1, &main, 0xffff);
	printf("ft_read errno = %d\n", errno);
	errno = 0;
	read(-1, &main, 0xffff);
	printf("read errno    = %d\n", errno);

	errno = 0;
	ft_read(-1, NULL, 0xffff);
	printf("ft_read errno = %d\n", errno);
	errno = 0;
	read(-1, NULL, 0xffff);
	printf("read errno    = %d\n", errno);


	return (0);
}
