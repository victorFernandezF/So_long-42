/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:08:26 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 11:28:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	load_images(t_game game)
{
	game.wall = ft_new_sprite(game.mlx, "sprites/wall.xpm");
	game.floor = ft_new_sprite(game.mlx, "sprites/floor.xpm");
	game.door = ft_new_sprite(game.mlx, "sprites/door.xpm");
	game.door_open = ft_new_sprite(game.mlx, "sprites/door_open.xpm");
	game.player_right = ft_new_sprite(game.mlx, "sprites/car_right.xpm");
	game.player_left = ft_new_sprite(game.mlx, "sprites/car_left.xpm");
	game.player_up = ft_new_sprite(game.mlx, "sprites/car_up.xpm");
	game.player_down = ft_new_sprite(game.mlx, "sprites/car_down.xpm");
	game.pokeball = ft_new_sprite(game.mlx, "sprites/pokeball.xpm");
	game.superball = ft_new_sprite(game.mlx, "sprites/superball.xpm");
	game.ultraball = ft_new_sprite(game.mlx, "sprites/ultraball.xpm");
	game.masterball = ft_new_sprite(game.mlx, "sprites/masterball.xpm");
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

t_image	get_game_objects(t_game game)
{
	int	w;
	int	h;
	int	max;

	w = game.map.width;
	h = game.map.height;
	if (w >= h)
		max = w;
	else
		max = h;
	if (max < 10)
		return (game.pokeball);
	if (max >= 10 && max <= 15)
		return (game.superball);
	if (max > 15)
		return (game.ultraball);
	return (game.masterball);
}
