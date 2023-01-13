/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:27 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 18:30:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	key_management_bonus(int keycode, t_game *game)
{
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	game->flag = 0;
	if (keycode == KESC)
		end_game(game);
	game->moves += 1;
	mlx_string_put(game->mlx, game->win.reference, 10, game->win.size.y - 10,
		0x000000, ft_itoa(game->moves - 1));
	mlx_string_put(game->mlx, game->win.reference, 10, game->win.size.y - 10,
		0xffffff, ft_itoa(game->moves));
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
 