/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:51:31 by victofer          #+#    #+#             */
/*   Updated: 2023/01/09 19:19:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	t_vector	img_position;

	img_position.x = 0;
	img_position.y = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win.reference);
		free(game->wall.reference);
		free(game->floor.reference);
		mlx_destroy(game->mlx);
		exit(0);
	}
	if (keycode == 2 || keycode == 124)
		*game = right_move(*game, game->map.map, 0, img_position);
	if (keycode == 0 || keycode == 123)
		*game = left_move(*game, game->map.map, 0, img_position);
	if (keycode == 13 || keycode == 126)
		*game = up_move(*game, game->map.map, 0, img_position);
	if (keycode == 1 || keycode == 125)
		*game = down_move(*game, game->map.map, 0, img_position);
	return (0);
}
