/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:51:31 by victofer          #+#    #+#             */
/*   Updated: 2023/01/09 11:32:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	t_vector	img_position;

	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win.reference);
		free(game->wall.reference);
		free(game->floor.reference);
		mlx_destroy(game->mlx);
		exit(0);
	}
	if (keycode == 2)
	{
		printf("D");
		img_position.x = 0;
		img_position.y = 0;
		game->map.map[1][1] = '0';
		game->map.map[1][1] = 'P';
		draw_map(*game, game->map.map, img_position);
	}
	return (0);
}
