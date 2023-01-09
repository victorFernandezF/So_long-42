/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:30:36 by victofer          #+#    #+#             */
/*   Updated: 2023/01/05 13:43:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

char	*ft_join_free(char *buffer, char *buff)
{
	char	*aux;

	aux = ft_strjoin_gnl(buffer, buff);
	free(buffer);
	return (aux);
}

char	*save_rest(char *rest)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	line = ft_calloc_gnl((ft_strlen_gnl(rest) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (rest[i])
		line[j++] = rest[i++];
	free(rest);
	return (line);
}

char	*get_line_gnl(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_calloc_gnl(i + 2, sizeof(char));
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] && rest[i] == '\n')
	{
		line[i++] = '\n';
	}
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char		*buffer;
	int			read_bytes;

	if (!str)
		str = ft_calloc_gnl(1, 1);
	buffer = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_join_free(str, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = get_line_gnl(str);
	str = save_rest(str);
	if (!line)
	{
		free(line);
		free(str);
		return (NULL);
	}
	return (line);
}
