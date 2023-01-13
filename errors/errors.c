/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:07:43 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 11:22:43 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

// Print a message, free the map array and exit the program
void	ft_error_free(char *msg, t_map map_list)
{
	ft_printf("RED ERROR:\n%s", msg);
	ft_free_map(map_list);
	exit (-1);
}

void	ft_free_map(t_map map_list)
{
	int	i;

	i = 0;
	while (map_list.map[i])
	{
		free(map_list.map[i]);
		i++;
	}
	free(map_list.map);
	map_list.map = NULL;
}

void	ft_error(char *msg)
{
	ft_printf(RED"ERROR:\n%s", msg);
	exit (-1);
}

void	game_over(t_game game)
{
	mlx_destroy_window(game.mlx, game.win.reference);
	free(game.player_left.reference);
	free(game.player_down.reference);
	free(game.player_right.reference);
	free(game.player_up.reference);
	free(game.floor.reference);
	free(game.door.reference);
	free(game.door_open.reference);
	free(game.wall.reference);
	free(game.pokeball.reference);
	free(game.superball.reference);
	free(game.ultraball.reference);
	free(game.masterball.reference);
	mlx_destroy(game.mlx);
	ft_free_map(game.map);
	exit(0);
}
