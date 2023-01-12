/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:47:50 by victofer          #+#    #+#             */
/*   Updated: 2023/01/12 12:16:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	open_window(t_game game)
{
	int			i;
	char		**map;
	t_vector	img_position;

	i = 0;
	map = game.map.map;
	img_position.x = 0;
	img_position.y = 0;
	game.win.name = "so_long";
	game.win.reference = mlx_new_window(game.mlx, game.win.size.x,
			game.win.size.y, game.win.name);
	game = load_images(game);
	draw_map(game, map, game.player_right.reference, img_position);
	return (game);
}
