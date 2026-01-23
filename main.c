#include <stdio.h>

#include "libasm.h"

int main(int argc, char *argv[])
{
	unsigned long length = 0;

	if (argc == 2)
	{
		length = ft_strlen(argv[1]);
		printf("Length: %ld\n", length);
	}
	else
		printf("usage: %s <string>\n", argv[0]);
	return (0);
}
