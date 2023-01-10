/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:16:51 by victofer          #+#    #+#             */
/*   Updated: 2023/01/10 12:34:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_game	game_start(t_game game)
{
	game.map = map_list_init();
	game.mlx = mlx_init();
	game.collect = 0;
	game.is_finish = 0;
	game.map.height = count_map_lines(game.map_file);
	game.map.map = map_reader(game.map_file, game.map);
	game.og_map = map_reader(game.map_file, game.map);
	game.map.width = (ft_strlen(game.map.map[0]) - 1);
	check_map_not_sqare(game.map);
	game.map = check_map(game.map);
	check_map_number_items(game.map);
	game.win.size.x = game.map.width * 64;
	game.win.size.y = game.map.height * 64;
	game = open_window(game);
	//printf("%s\n", game.og_map[1]);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	//atexit(show_leaks);
	if (!check_args(argc, argv[1]))
		return (0);
	game.map_file = argv[1];
	game = game_start(game);
	mlx_key_hook(game.win.reference, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
