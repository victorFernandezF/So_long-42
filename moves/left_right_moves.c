/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:33:21 by victofer          #+#    #+#             */
/*   Updated: 2023/01/10 19:29:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static int	check_player_wall(char c1, char c2)
{
	if (c1 == 'P' && c2 != '1' && c2 != 'E')
		return (1);
	return (0);
}

static int	chek_something(int i, int j, int dir, t_game game)
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
			game.is_finish = chek_something(i, j, 0, game);
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
			game.is_finish = chek_something(i, j, 1, game);
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

	(void)img_pos;
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

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		while (j < game.map.width && game.flag == 0)
		{
			if (map[i][j] == 'P' && map[i + 1][j] != '1'
				&& map[i + 1][j] != 'E')
			{
				if (map[i + 1][j] == 'C')
					game.collect += 1;
				map[i][j] = '0';
				game.flag = 1;
				map[i + 1][j] = 'P';
			}
			j++;
		}
		i++;
	}
	game = check_door(game);
	draw_map(game, map, game.player_down.reference, img_pos);
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


