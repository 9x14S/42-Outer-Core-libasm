#ifndef LIBASM_H
# define LIBASM_H

#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);
ssize_t	ft_write(int fd, void *data, size_t size);
ssize_t	ft_read(int fd, void *buffer, size_t size);

#endif /* LIBASM_H */
