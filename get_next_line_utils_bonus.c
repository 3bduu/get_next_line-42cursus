/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:00:31 by abenlahb          #+#    #+#             */
/*   Updated: 2022/11/14 00:18:24 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	x;

	x = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!p)
		return (NULL);
	while (s1[x])
	{
		p[x] = s1[x];
		x++;
	}
	x = 0;
	while (s2[x])
	{
		p[ft_strlen((char *)s1) + x] = s2[x];
		x++;
	}
	p[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = 0;
	free((void *)s1);
	s1 = NULL;
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = 0;
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
