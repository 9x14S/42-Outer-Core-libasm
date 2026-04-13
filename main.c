#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libasm.h"

#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define RESET "\e[0m"

#define PASS GREEN "PASS" RESET
#define FAIL RED "FAIL" RESET

#define TEST(x, y) do {\
	long x_val = (long)x;\
	long y_val = (long)y;\
	printf("TESTING: " #x " and " #y "\nRESULT: (%ld), (%ld)\nGRADE:%s\n",\
		x_val, y_val, x_val == y_val ? PASS : FAIL );\
} while (0)

#define TEST_CMP(x, y) do {\
	long x_val = (long)x;\
	long y_val = (long)y;\
	printf("TESTING: " #x " and " #y "\nGRADE:%s\n",\
		strcmp((char *)x_val, (char *)y_val) == 0 ? PASS : FAIL);\
} while (0)

#define TEST_ERRNO(x, y) do {\
	errno = 0;						\
	ssize_t x_val = (ssize_t)x;		\
	int		x_errno = errno;		\
	ssize_t y_val = (ssize_t)y;		\
	int		y_errno = errno;		\
	printf("TESTING: " #x " and " #y "\nRESULT: (%ld), (%ld)\nERRNO: (%d), (%d)\n"	\
			"GRADE:%s\n", x_val, y_val, x_errno, y_errno,							\
			x_errno == y_errno && x_val == y_val ? PASS : FAIL );					\
} while (0)

int main(void)
{
	// strlen tests
	TEST(ft_strlen("aaa"), strlen("aaa"));
	TEST(ft_strlen("a"), strlen("a"));
	TEST(ft_strlen("a"), strlen("b"));
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
	TEST_CMP(ft_strdup(""), strdup(""));
	TEST_CMP(ft_strdup("aaaaaaaaaaaaa"), strdup("aaaaaaaaaaaaa"));

	// write tests
	#define TEST_STR "TEST42\n"
	TEST_ERRNO(ft_write(0, NULL, 0), write(0, NULL, 0));
	TEST_ERRNO(ft_write(1, NULL, 0xffff), write(1, NULL, 0xffff));
	TEST_ERRNO(ft_write(-1, &main, 0xffff), write(-1, &main, 0xffff));
	TEST_ERRNO(ft_write(-1, NULL, 0xffff), write(-1, NULL, 0xffff));
	TEST_ERRNO(ft_write(1, TEST_STR, sizeof(TEST_STR)), write(1, TEST_STR, sizeof(TEST_STR)));
	TEST_ERRNO(ft_write(1, "", 0), write(1, "", 0));
	#undef TEST_STR

	// read tests (shouldn't crash but also shouldn't do anything)
	TEST_ERRNO(ft_read(0, NULL, 0), read(0, NULL, 0));
	TEST_ERRNO(ft_read(-1, &main, 0xffff), read(-1, &main, 0xffff));
	TEST_ERRNO(ft_read(-1, NULL, 0xffff), read(-1, NULL, 0xffff));

	// TODO: Bonus tests
	printf("list size = %d\n", ft_list_size(NULL));
	t_list a = {.data = NULL, .next = NULL};
	t_list b = {.data = NULL, .next = &a};
	t_list c = {.data = NULL, .next = &b};

	printf("list size = %d\n", ft_list_size(&c));

	return (0);
}
