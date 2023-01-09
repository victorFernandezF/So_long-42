/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:07:43 by victofer          #+#    #+#             */
/*   Updated: 2023/01/05 13:45:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

// Print a message, free the map array and exit the program
void	ft_error_free(char *msg, t_map map_list)
{
	if (map_list.map)
	{
		free (map_list.map);
	}
	ft_printf("ERROR:\n%s", msg);
	exit (-1);
}

void	ft_error_destroy(char *msg, t_game game)
{
	mlx_destroy_image(game.mlx, game.wall.reference);
	mlx_destroy_window(game.mlx, game.win.reference);
	mlx_destroy(game.mlx);
	ft_printf("ERROR:\n%s", msg);
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
	ft_printf("ERROR:\n%s", msg);
	exit (-1);
}
