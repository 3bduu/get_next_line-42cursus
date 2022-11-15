/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:40:04 by abenlahb          #+#    #+#             */
/*   Updated: 2022/11/14 23:25:50 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buff;
	ssize_t		rd;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd >= 0)
	{
		buff[rd] = '\0';
		remainder = ft_strjoin(remainder, buff);
		if (where_is_new_line(remainder, '\n') != -1)
			return (join_with_new_line(&remainder, &buff));
		if (!rd && remainder[0] == '\0')
			break ;
		if (!rd)
			return (remainder_func(&remainder, &buff));
		rd = read(fd, buff, BUFFER_SIZE);
	}
	return (free_func(&buff, &remainder));
}

char	*free_func(char **buff, char **remainder)
{
	free(*buff);
	free(*remainder);
	*remainder = NULL;
	return (NULL);
}

char	*remainder_func(char **str, char **buff)
{
	char	*rm;

	rm = ft_strdup(*str);
	free(*str);
	*str = NULL;
	free(*buff);
	return (rm);
}

char	*join_with_new_line(char **remainder, char **buff)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	str = ft_strdup(*remainder);
	j = where_is_new_line(str, '\n');
	free(*remainder);
	*remainder = ft_strdup(str + (j + 1));
	str[j + 1] = 0;
	free(*buff);
	return (str);
}

int	where_is_new_line(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
