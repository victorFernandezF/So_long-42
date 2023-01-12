/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:51:31 by victofer          #+#    #+#             */
/*   Updated: 2023/01/12 12:55:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	end_game(t_game *game)
{
	ft_printf(BLUE":( YOU CLOSE THE GAME. SEE YOU SOON.\n");
	game_over(*game);
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
	game->moves += 1;
	ft_printf(YELLOW"Moves: %i\n", game->moves);
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
