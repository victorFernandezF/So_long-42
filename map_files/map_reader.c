/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:33:18 by victofer          #+#    #+#             */
/*   Updated: 2023/01/05 13:34:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

// Return the number of lines of the map (Height)
int	count_map_lines(char *file)
{
	int		num_line;
	int		fd;
	int		num_read;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	num_line = 1;
	while (1)
	{
		num_read = read(fd, &c, 1);
		if (num_read == 0)
			break ;
		if (num_read < 0)
			return (-1);
		if (c == '\n')
			num_line++;
	}
	close(fd);
	return (num_line);
}

char	**malloc_cols(char *file)
{
	char	**map;
	int		lines;

	lines = count_map_lines(file);
	if (lines <= 0)
		ft_error("NO FILE");
	map = (char **)malloc(sizeof(char *) * lines);
	if (!map)
		ft_error("SOMETHING WERE WRONG");
	return (map);
}

// Create an array and returnit with the map inside
char	**map_reader(char *file, t_map map_list)
{
	int		i;
	char	**map;
	int		fd;

	map = malloc_cols(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < map_list.height)
	{
		map[i++] = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
