/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:50:22 by victofer          #+#    #+#             */
/*   Updated: 2023/01/11 11:56:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	check_door(t_game game)
{
	int			i;
	int			j;

	if (game.map.objects == game.collect)
	{
		i = 0;
		while (i < game.map.height)
		{
			j = 0;
			while (j < game.map.width)
			{
				if (game.map.map[i][j] == 'E')
				{
					game.map.map[i][j] = 'F';
				}
				j++;
			}
			i++;
		}
	}
	return (game);
}

int	check_player_wall(char c1, char c2)
{
	if (c1 == 'P' && c2 != '1' && c2 != 'E')
		return (1);
	return (0);
}

int	chek_open_door(int i, int j, int dir, t_game game)
{
	if (dir == 0)
		if (game.og_map[i][j + 1] == 'E')
			return (1);
	if (dir == 1)
		if (game.og_map[i][j - 1] == 'E')
			return (1);
	if (dir == 2)
		if (game.og_map[i - 1][j] == 'E')
			return (1);
	if (dir == 3)
		if (game.og_map[i + 1][j] == 'E')
			return (1);
	return (0);
}

t_game	is_game_over(t_game game, char **map, void *player, t_vector img_pos)
{
	if (game.is_finish == 1)
		last_map(game, map, player, img_pos);
	draw_map(game, map, player, img_pos);
	return (game);
}
