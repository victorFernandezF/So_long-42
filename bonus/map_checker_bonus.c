/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:40:43 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 18:45:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

// Save the map items in the map_list 
t_map	check_map_items_bonus(t_map map_list)
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
				else if (map[i][j] != 'S' || map[i][j] != 's')
					map_list.bad_char = 1;
			}
		}
	}
	return (map_list);
}
