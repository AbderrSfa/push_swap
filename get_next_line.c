/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:07:52 by asfaihi           #+#    #+#             */
/*   Updated: 2021/07/16 10:31:29 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	get_line(char **str, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	*line = ft_substr(str[fd], 0, i);
	if (!str[fd][i])
	{
		temp = str[fd];
		str[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = str[fd];
		str[fd] = ft_strdup((str[fd]) + i + 1);
		free(temp);
	}
	if (!str[fd] || !*line)
		return (-1);
	if (n || (n == 0 && str[fd] != NULL))
		return (1);
	return (-1);
}

int	ft_read_line(int fd, char *str[4864], char *buf)
{
	char	*temp;
	int		n;

	n = read(fd, buf, BUFFER_SIZE);
	while (n)
	{
		temp = str[fd];
		buf[n] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if (!str[fd])
			return (-1);
		free(temp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*str[4864];
	char			*temp;
	int				n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
		|| !buf || read(fd, buf, 0) == -1)
		return (-1);
	if (!str[fd])
	{
		str[fd] = ft_strdup("");
		if (!str[fd])
			return (-1);
	}
	if (ft_read_line(fd, str, buf) == -1)
		return (-1);
	free(buf);
	return (get_line(str, n, line, fd));
}
