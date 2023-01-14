/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:51:31 by victofer          #+#    #+#             */
/*   Updated: 2023/01/14 11:31:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	end_game(t_game *game)
{
	ft_printf(MAG"YOU CLOSED THE GAME :( \n"WHITE);
	game_over(*game);
	return (0);
}

int	check_allowed_keys(int k)
{
	if (k == KA || k == KLEFT || k == KW || k == KUP || k == KD
		|| k == KRIGHT || k == KDOWN)
		return (1);
	return (0);
}

int	key_management(int keycode, t_game *game)
{
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	game->flag = 0;
	if (keycode == KESC)
		end_game(game);
	if (check_allowed_keys(keycode))
	{
		game->moves += 1;
		ft_printf(YELLOW"Moves: %i\n"WHITE, game->moves);
	}
	if (keycode == KD || keycode == KRIGHT)
		*game = right_move(*game, game->map.map, img_position);
	if (keycode == KA || keycode == KLEFT)
		*game = left_move(*game, game->map.map, img_position);
	if (keycode == KW || keycode == KUP)
		*game = up_move(*game, game->map.map, img_position);
	if (keycode == KS || keycode == KDOWN)
		*game = down_move(*game, game->map.map, img_position);
	return (0);
}
