/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:16:33 by victofer          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

t_game	draw_aux(char map, t_game game, void *player, t_vector img_pos)
{
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
	else
		mlx_put_image_to_window(game.mlx, game.win.reference,
			game.floor.reference, img_pos.x, img_pos.y);
	return (game);
}

t_game	draw_map(t_game game, char **map, void *player, t_vector img_position)
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
			draw_aux(map[i][j], game, player, img_position);
			j++;
		}
		i++;
	}
	return (game);
}

t_game	last_map(t_game game, char **map, void *player, t_vector img_pos)
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
			draw_aux(map[i][j], game, player, img_pos);
			j++;
		}
		i++;
	}
	ft_printf(GREEN"CONGRATULATIONS.\n YOU WON 🥇\n");
	game_over(game);
	return (game);
}
