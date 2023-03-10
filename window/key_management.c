/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:51:31 by victofer          #+#    #+#             */
/*   Updated: 2023/01/16 13:38:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	end_game(t_game *game)
{
	ft_printf(MAG"YOU CLOSED THE GAME :( \n"WHITE);
	game_over(*game);
	return (0);
}

t_game	print_moves(t_game game)
{
	game.moves += 1;
	ft_printf(YELLOW"Moves: %i\n"WHITE, game.moves);
	return (game);
}

int	key_management(int keycode, t_game *game)
{
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	game->flag = 0;
	if (keycode == KESC)
		end_game(game);
	if (keycode == KD || keycode == KRIGHT)
		*game = right_move(*game, game->map.map, img_position, -1);
	if (keycode == KA || keycode == KLEFT)
		*game = left_move(*game, game->map.map, img_position, -1);
	if (keycode == KW || keycode == KUP)
		*game = up_move(*game, game->map.map, img_position, -1);
	if (keycode == KS || keycode == KDOWN)
		*game = down_move(*game, game->map.map, img_position, -1);
	return (0);
}
