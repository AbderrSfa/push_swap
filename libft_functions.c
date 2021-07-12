/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:27:47 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/12 16:27:48 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (1);
	else
		return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	l;
	char	*a;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	a = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	i = -1;
	l = 0;
	while (s1[++i])
		a[i] = s1[i];
	while (s2[l])
		a[i++] = s2[l++];
	a[i] = '\0';
	return (a);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*a;

	a = malloc(ft_strlen(s1) + 1);
	if (a == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	long	a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 1;
	while (((*str <= 13) && (*str >= 9)) || (*str == 32))
		str++;
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			c = -1;
		b++;
		str++;
	}
	if (b > 1)
		return (0);
	while ((*str <= '9') && (*str >= '0'))
	{
		a = (*str - 48) + a * 10;
		str++;
	}
	return (a * c);
}

static size_t	ft_smallest(const char *s, unsigned int start, size_t len)
{
	if (len > ft_strlen(s + start))
		return (ft_strlen(s + start) + 1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	i = 0;
	x = (char *)malloc(sizeof(char) * ft_smallest(s, start, len));
	if (x == 0)
		return (NULL);
	while (i < (ft_smallest(s, start, len) - 1))
	{
		x[i] = s[i + start];
		i++;
	}
	x[i] = '\0';
	return (x);
}

static int	count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*ft_word_splitter(char *d, char *f)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(f - d + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (d != f)
	{
		p[i] = *d;
		d++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	freeall(int i, char **p)
{
	int	j;

	j = -1;
	while (j++ <= i)
		free(p[j]);
	free(p);
}

char	**ft_split(char const *s, char v)
{
	char	**p;
	char	*f;
	size_t	i;

	p = (char **)malloc(sizeof(char *) * (count(s, v) + 1));
	if (s == NULL || !p)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == v)
			s++;
		f = (char *)s;
		while (*f != v && *f != '\0')
			f++;
		if (s == f)
			break ;
		p[i] = ft_word_splitter((char *)s, f);
		if (!p[i])
			freeall(i, p);
		s = f;
		i++;
	}
	p[i] = NULL;
	return (p);
}