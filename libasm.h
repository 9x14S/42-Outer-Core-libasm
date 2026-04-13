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

// Bonus
struct s_list
{
	void *data;
	struct s_list *next;
};

typedef struct s_list t_list;

int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *));

#endif /* LIBASM_H */
