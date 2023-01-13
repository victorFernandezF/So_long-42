/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:50:22 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 19:48:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	chek_enemy(int i, int j, int dir, t_game game)
{
	if (dir == 0)
		if (game.og_map[i][j + 1] == 'S')
			return (1);
	if (dir == 1)
		if (game.og_map[i][j - 1] == 'S')
			return (1);
	if (dir == 2)
		if (game.og_map[i - 1][j] == 'S')
			return (1);
	if (dir == 3)
		if (game.og_map[i + 1][j] == 'S')
			return (1);
	return (0);
}

int	check_player_wall_bonus(char c1, char c2)
{
	if (c1 == 'P' && c2 != '1' && c2 != 'E' && c2 != 'S')
		return (1);
	return (0);
}

t_game	is_game_over_b(t_game game, char **map, void *player, t_vector img_pos)
{
	if (game.map.enemy == 1)
		end_game_bonus(&game);
	if (game.is_finish == 1)
		last_map_bonus(game, map, player, img_pos);
	draw_map_bonus(game, map, player, img_pos);
	return (game);
}

int	end_game_bonus(t_game *game)
{
	ft_printf(MAG"YOU LOSE.\n"WHITE);
	game_over(*game);
	return (0);
}

