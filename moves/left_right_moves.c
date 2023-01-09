/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:33:21 by victofer          #+#    #+#             */
/*   Updated: 2023/01/09 14:13:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	right_move(t_game game, char **map, int flag)
{
	int			i;
	int			j;
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i][j + 1] != '1')
			{
				map[i][j] = '0';
				flag = 1;
				map[i][j + 1] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_right.reference, img_position);
		i++;
	}
	return (game);
}

t_game	left_move(t_game game, char **map, int flag)
{
	int			i;
	int			j;
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i][j - 1] != '1')
			{
				map[i][j] = '0';
				flag = 1;
				map[i][j - 1] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_left.reference, img_position);
		i++;
	}
	return (game);
}

t_game	up_move(t_game game, char **map, int flag)
{
	int			i;
	int			j;
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i - 1][j] != '1')
			{
				map[i][j] = '0';
				flag = 1;
				map[i - 1][j] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_up.reference, img_position);
		i++;
	}
	return (game);
}

t_game	down_move(t_game game, char **map, int flag)
{
	int			i;
	int			j;
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i + 1][j] != '1')
			{
				map[i][j] = '0';
				flag = 1;
				map[i + 1][j] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_down.reference, img_position);
		i++;
	}
	return (game);
}
