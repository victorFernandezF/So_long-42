/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:47:50 by victofer          #+#    #+#             */
/*   Updated: 2023/01/09 12:06:21 by victofer         ###   ########.fr       */
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
	game.wall = ft_new_sprite(game.mlx, "img/wall.xpm");
	game.floor = ft_new_sprite(game.mlx, "img/floor.xpm");
	game.door = ft_new_sprite(game.mlx, "img/door.xpm");
	game.object = ft_new_sprite(game.mlx, "img/object.xpm");
	game.player_right = ft_new_sprite(game.mlx, "img/player.xpm");
	draw_map(game, map, img_position);
	return (game);
}

static t_game	draw_aux(char map, t_game game, t_vector img_position)
{
	if (map == '1')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.wall.reference, img_position.x, img_position.y);
	else if (map == 'E')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.door.reference, img_position.x, img_position.y);
	else if (map == 'C')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.object.reference, img_position.x, img_position.y);
	else if (map == 'P')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.player_right.reference, img_position.x, img_position.y);
	else
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.floor.reference, img_position.x, img_position.y);
	return (game);
}

t_game	draw_map(t_game game, char **map, t_vector img_position)
{
	int			i;
	int			j;	

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		img_position.y = i * 64;
		while (j < game.map.width)
		{
			img_position.x = j * 64;
			draw_aux(map[i][j], game, img_position);
			j++;
		}
		i++;
	}
	return (game);
}

