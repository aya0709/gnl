/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataira <ataira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:12:32 by ataira            #+#    #+#             */
/*   Updated: 2023/03/14 13:08:01 by ataira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*p;

	if (size != 0)
	{
		if (count > SIZE_MAX / size)
			return (NULL);
	}
	len = count * size;
	if (len == 0)
		len = 1;
	p = malloc(len);
	if (p == NULL)
		return (NULL);
	while (len > 0)
	{
		((unsigned char *)p)[len - 1] = '\0';
		len--;
	}
	return (p);
}

int	ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	*ucs;

	i = 0;
	if (s == NULL)
		return (-1);
	len = ft_strlen(s);
	ucs = (unsigned char *)s;
	while (i <= len)
	{
		if (ucs[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	if (size <= len)
		len = size - 1;
	while (i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}
