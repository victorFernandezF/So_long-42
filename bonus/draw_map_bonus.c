/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:48:08 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 19:03:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	open_window_bonus(t_game game)
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
	draw_map_bonus(game, map, game.player_right.reference, img_position);
	return (game);
}

t_game	draw_aux_bonus(char map, t_game game, void *player, t_vector img_pos)
{	
	game.object = get_game_objects(game);
	if (map == '1')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.wall.reference, img_pos.x, img_pos.y);
	else if (map == 'E')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.door.reference, img_pos.x, img_pos.y);
	else if (map == 'C')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.object.reference, img_pos.x, img_pos.y);
	else if (map == 'P')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			player, img_pos.x, img_pos.y);
	else if (map == 'F')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.door_open.reference, img_pos.x, img_pos.y);
	else if (map == 'S')
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.enemy.reference, img_pos.x, img_pos.y);
	else
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.floor.reference, img_pos.x, img_pos.y);
	return (game);
}

t_game	draw_map_bonus(t_game game, char **map, void *player, t_vector img_pos)
{
	int			i;
	int			j;	

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		img_pos.y = i * 64;
		while (j < game.map.width)
		{
			img_pos.x = j * 64;
			draw_aux_bonus(map[i][j], game, player, img_pos);
			j++;
		}
		i++;
	}
	return (game);
}

t_game	last_map_bonus(t_game game, char **map, void *player, t_vector img_pos)
{
	int			i;
	int			j;	

	i = 0;
	while (i < game.map.height)
	{
		j = 0;
		img_pos.y = i * 64;
		while (j < game.map.width)
		{
			img_pos.x = j * 64;
			draw_aux_bonus(map[i][j], game, player, img_pos);
			j++;
		}
		i++;
	}
	ft_printf(GREEN"CONGRATULATIONS. 🥇\n"WHITE);
	ft_printf(GREEN"YOU WON IN %i MOVES \n"WHITE, game.moves);
	if (game.moves == 42)
		ft_printf(YELLOW" 42 MOVES, NICE\n"WHITE, game.moves);
	game_over(game);
	return (game);
}
