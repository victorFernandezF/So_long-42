/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:33:21 by victofer          #+#    #+#             */
/*   Updated: 2023/01/11 11:31:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*
** First check if is posible to move the player
** one step to the right. Thne move it 
** when 'D' or 'right arrow' is pressed.
*/
t_game	right_move(t_game game, char **map, t_vector img_pos)
{
	int			i;
	int			j;

	(void)img_pos;
	i = -1;
	while (++i < game.map.height)
	{
		j = -1;
		while (++j < game.map.width && game.flag == 0)
		{
			game.is_finish = chek_open_door(i, j, 0, game);
			if (check_player_wall(map[i][j], map[i][j + 1]))
			{
				if (map[i][j + 1] == 'C')
					game.collect += 1;
				map[i][j] = '0';
				game.flag = 1;
				map[i][j + 1] = 'P';
			}
		}
	}
	game = check_door(game);
	game = is_game_over(game, map, game.player_right.reference, img_pos);
	return (game);
}

/*
** First check if is posible to move the player
** one step to the left. Thne move it 
** when 'A' or 'left arrow' is pressed.
*/
t_game	left_move(t_game game, char **map, t_vector img_pos)
{
	int			i;
	int			j;

	(void)img_pos;
	i = -1;
	while (++i < game.map.height)
	{
		j = -1;
		while (++j < game.map.width && game.flag == 0)
		{
			game.is_finish = chek_open_door(i, j, 1, game);
			if (check_player_wall(map[i][j], map[i][j - 1]))
			{
				if (map[i][j - 1] == 'C')
					game.collect += 1;
				map[i][j] = '0';
				game.flag = 1;
				map[i][j - 1] = 'P';
			}
		}
	}
	game = check_door(game);
	game = is_game_over(game, map, game.player_left.reference, img_pos);
	return (game);
}

/*
** First check if is posible to move the player
** one step up. Thne move it 
** when 'W' or 'up arrow' is pressed.
*/
t_game	up_move(t_game game, char **map, t_vector img_pos)
{
	int			i;
	int			j;

	i = -1;
	while (++i < game.map.height)
	{
		j = -1;
		while (++j < game.map.width && game.flag == 0)
		{
			if (map[i][j] == 'P' && map[i - 1][j] != '1'
				&& map[i - 1][j] != 'E')
			{
				if (map[i - 1][j] == 'C')
					game.collect += 1;
				if (map[i - 1][j] == 'F')
					game.is_finish = 1;
				map[i][j] = '0';
				game.flag = 1;
				map[i - 1][j] = 'P';
			}
		}
	}
	game = check_door(game);
	game = is_game_over(game, map, game.player_up.reference, img_pos);
	return (game);
}

/*
** First check if is posible to move the player
** one step down. Thne move it 
** when 'S' or 'down arrow' is pressed.
*/
t_game	down_move(t_game game, char **map, t_vector img_pos)
{
	int			i;
	int			j;

	i = -1;
	while (++i < game.map.height)
	{
		j = -1;
		while (++j < game.map.width && game.flag == 0)
		{
			if (map[i][j] == 'P' && map[i + 1][j] != '1'
					&& map[i + 1][j] != 'E')
			{
				if (map[i + 1][j] == 'C')
					game.collect += 1;
				if (map[i + 1][j] == 'F')
					game.is_finish = 1;
				map[i][j] = '0';
				game.flag = 1;
				map[i + 1][j] = 'P';
			}
		}
	}
	game = check_door(game);
	game = is_game_over(game, map, game.player_down.reference, img_pos);
	return (game);
}
