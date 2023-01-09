/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:08:26 by victofer          #+#    #+#             */
/*   Updated: 2023/01/09 14:03:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	load_images(t_game game)
{
	game.wall = ft_new_sprite(game.mlx, "img/wall.xpm");
	game.floor = ft_new_sprite(game.mlx, "img/floor.xpm");
	game.door = ft_new_sprite(game.mlx, "img/door.xpm");
	game.object = ft_new_sprite(game.mlx, "img/object.xpm");
	game.player_right = ft_new_sprite(game.mlx, "img/tanky_right.xpm");
	game.player_left = ft_new_sprite(game.mlx, "img/tanky_left.xpm");
	game.player_up = ft_new_sprite(game.mlx, "img/tanky_up.xpm");
	game.player_down = ft_new_sprite(game.mlx, "img/tanky_down.xpm");
	return (game);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}