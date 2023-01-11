/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:39:03 by victofer          #+#    #+#             */
/*   Updated: 2023/01/11 19:04:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*
 * Check:
 *		Correct number of args
 *		Map extension (*,ber)
 * 		Map file is able to open 
 */
int	check_args(int n, char *str)
{
	if (n != 2)
	{
		ft_error("Incorrect number of arguments.");
		return (0);
	}
	if (!check_ber_file(str))
	{
		ft_error("The map must be a '.ber' file");
		return (0);
	}
	if (open(str, O_RDONLY) < 0)
	{
		ft_error("Map not found");
		return (0);
	}
	return (1);
}

/*
** Check the *.ber file extension. 
** Return 0 if map extension is not '.ber'
** Return 1  if map extension is correct
*/
int	check_ber_file(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] == '.' && (str[i - 3] == 'b'
			&& str [i - 2] == 'e') && (str[i - 1] == 'r'))
		return (1);
	return (0);
}

/* Check the correct items in the map
 *		Only 1 Player.
 *		At Least 1 Collectable Object.
 *		At Least 1 Exit.
 *		No other chars than (1, 0, E, C, P).
*/
int	check_map_number_items(t_map map)
{
	if (map.bad_char == 1)
		ft_error_free("Map only allowed Chars: 1, 0 , C, P, E", map);
	if (map.objects <= 0)
		ft_error_free("It must be at least one object (C)", map);
	if (map.player <= 0)
		ft_error_free("It must be at least one player (P)", map);
	if (map.exit <= 0)
		ft_error_free("It must be at least one exit (E)", map);
	if (map.player > 1)
		ft_error_free("No more than one player (P) allowed in the map.", map);
	return (0);
}

// Save the map items in the map_list 
t_map	check_map_items(t_map map_list)
{
	int			i;
	size_t		j;
	char		**map;

	map = map_list.map;
	i = 0;
	while (++i < map_list.height)
	{
		j = 0;
		while (++j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] != '0' && map[i][j] != '1')
			{
				if (map[i][j] == 'C' || map[i][j] == 'c')
					map_list.objects = map_list.objects + 1;
				else if (map[i][j] == 'P' || map[i][j] == 'p')
					map_list.player = map_list.player + 1;
				else if (map[i][j] == 'E' || map[i][j] == 'e')
					map_list.exit = map_list.exit + 1;
				else
					map_list.bad_char = 1;
			}
		}
	}
	return (map_list);
}

// Check all map Stuff
t_map	check_map(t_map map_list)
{
	int		i;

	i = 0;
	while (map_list.map[i])
	{
		if (i == 0)
		{
			if (check_first_line(map_list.map[i], map_list) == 0)
				ft_error("Map must be closed (top/bottom line)");
		}
		else if (i == map_list.height - 1)
		{
			if (check_last_line(map_list.map[i], map_list) == 0)
				ft_error("Map must be closed (top/bottom line)");
		}
		else
		{
			if (check_middle_lines(map_list.map[i], map_list) == 0)
				ft_error("Map have to be closed (Middle lines)");
		}
		i++;
	}
	map_list = check_map_items(map_list);
	return (map_list);
}
