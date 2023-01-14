/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:27 by victofer          #+#    #+#             */
/*   Updated: 2023/01/14 11:29:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	key_management_bonus(int keycode, t_game *g)
{
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	g->flag = 0;
	if (keycode == KESC)
		end_game(g);
	if (check_allowed_keys(keycode))
	{
		g->moves += 1;
		put_string_moves(*g);
	}
	if (keycode == KD || keycode == KRIGHT)
		*g = right_move_bonus(*g, g->map.map, img_position, -1);
	if (keycode == KA || keycode == KLEFT)
		*g = left_move_bonus(*g, g->map.map, img_position, -1);
	if (keycode == KW || keycode == KUP)
		*g = up_move_bonus(*g, g->map.map, img_position, -1);
	if (keycode == KS || keycode == KDOWN)
		*g = down_move_bonus(*g, g->map.map, img_position, -1);
	return (0);
}

void	put_string_moves(t_game game)
{
	char		*line;
	char		*line2;

	line = ft_itoa(game.moves);
	line2 = ft_itoa(game.moves - 1);
	mlx_string_put(game.mlx, game.win.reference, 55,
		game.win.size.y - 15, 0x000000, line2);
	mlx_string_put(game.mlx, game.win.reference, 55,
		game.win.size.y - 15, 0xffffff, line);
	free(line);
	free(line2);
}
