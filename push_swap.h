#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_array		t_array;
struct						s_array
{
	int						*array;
	int						size;
	int						size_used;
};

typedef struct s_stacks		t_stacks;
struct						s_stacks
{
	t_array					stack_a;
	t_array					stack_b;
};

// Libft functions:
void		ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_isdigit(int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
long		ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char v);

// push_swap functions:
int			ft_put_error(char *message, t_stacks *stacks);
int			are_args_valid(char **argv);
int			duplicate_arg(t_stacks *stacks, int num);
void		init_stacks(int argc, t_stacks *stacks);
t_stacks	ft_fill_stacks(int argc, char **argv);

#endif