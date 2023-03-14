/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataira <ataira@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:58:35 by ataira            #+#    #+#             */
/*   Updated: 2023/03/14 14:39:39 by ataira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_setexblock(char *buf, char *block, char *line)
{
	int	i;
	int	len;
	int	len_line;

	i = 0;
	len_line = 0;
	len = ft_strchr(block, '\n');
	line = ft_calloc(len + len_line, sizeof(char));
	while (len > 0)
	{
		line[len_line + len - 1] = block[len - 1];
		len--;
	}
	buf = ft_calloc(ft_strlen(block) - len, sizeof(char));
	while (i < ft_strlen(block) - len)
	{
		buf[i] = block[ft_strchr(block, '\n') + 1+ i];
		i++;
	}
	printf("buf_func:%p\n", buf);
	return (line);
}

char	*ft_setmem(int rc, char *buf, char *str)
{
	if (buf == NULL)
	{
		buf = ft_calloc(rc, sizeof(char));
		if (buf == NULL)
			return (NULL);
		buf = ft_strjoin(buf, str);
	}
	else
	{
		buf = ft_strjoin(buf, str);
	}
	return (buf);
}

char	*ft_get_block(int fd, char *buf)
{
	int		rc;
	char	*str;

	rc = 1;
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (rc != 0 && ft_strchr(str, '\n') == -1)
	{
		rc = read(fd, str, BUFFER_SIZE);
		buf = ft_setmem(rc, buf, str);
	}
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*block;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (buf != NULL)
		line = buf;
	// if (ft_strchr(line, '\n') != -1)
	// {
	// 	printf("a\n");
	// 	block = ft_calloc(ft_strchr(line, '\n'), sizeof(char));
	// 	ft_strlcpy(block, line, ft_strchr(line, '\n'));
	// 	ft_strlcpy(buf, line + ft_strchr(line, '\n') + 1, ft_strlen(line)
	// 			- ft_strchr(line, '\n'));
	// 	free(block);
	// 	return (line);
	// }
	block = ft_get_block(fd, buf);
	printf("buf:%p\n", buf);	
	free(buf);
	if (block == NULL)
		return (NULL);
	line = ft_setexblock(buf, block, line);
	printf("buf:%p\n", buf);
	free(block);
	return (line);
}
