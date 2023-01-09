/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:33:21 by victofer          #+#    #+#             */
/*   Updated: 2023/01/09 19:33:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*
** First check if is posible to move the player
** one step to the right. Thne move it 
** when 'D' or 'right arrow' is pressed.
*/
t_game	right_move(t_game game, char **map, int flag, t_vector img_pos)
{
	int			i;
	int			j;

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i][j + 1] != '1'
				&& map[i][j + 1] != 'E')
			{
				if (map[i][j + 1] == 'C')
					game.collect = game.collect + 1;
				map[i][j] = '0';
				flag = 1;
				map[i][j + 1] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_right.reference, img_pos);
		i++;
	}	return (game);
}

/*
** First check if is posible to move the player
** one step to the left. Thne move it 
** when 'A' or 'left arrow' is pressed.
*/
t_game	left_move(t_game game, char **map, int flag, t_vector img_pos)
{
	int			i;
	int			j;

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i][j - 1] != '1'
				&& map[i][j - 1] != 'E')
			{
				if (map[i][j - 1] == 'C')
					game.collect += 1;
				map[i][j] = '0';
				flag = 1;
				map[i][j - 1] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_left.reference, img_pos);
		i++;
	}	return (game);
}

/*
** First check if is posible to move the player
** one step up. Thne move it 
** when 'W' or 'up arrow' is pressed.
*/
t_game	up_move(t_game game, char **map, int flag, t_vector img_pos)
{
	int			i;
	int			j;

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i - 1][j] != '1'
				&& map[i - 1][j] != 'E')
			{
				if (map[i - 1][j] == 'C')
					game.collect += 1;
				map[i][j] = '0';
				flag = 1;
				map[i - 1][j] = 'P';
			}
			j++;
		}
		draw_map(game, map, game.player_up.reference, img_pos);
		i++;
	}	return (game);
}

/*
** First check if is posible to move the player
** one step down. Thne move it 
** when 'S' or 'down arrow' is pressed.
*/
t_game	down_move(t_game game, char **map, int flag, t_vector img_pos)
{
	int			i;
	int			j;

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && flag == 0)
		{
			if (map[i][j] == 'P' && map[i + 1][j] != '1'
				&& map[i + 1][j] != 'E')
			{
				if (map[i + 1][j] == 'C')
					game.collect += 1;
				map[i][j] = '0';
				flag = 1;
				map[i + 1][j] = 'P';
			}
			j++;
		}
		i++;
	}
	draw_map(game, map, game.player_down.reference, img_pos);
	game = check_door(game);
	return (game);
}

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
// CREATE A SPRITE FOR THE OPEN DOOR AND SUSTITUTE BY F IN MAP