/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:18:16 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 19:27:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

// init the map list with all fields to 0
t_map	map_list_init(void)
{
	t_map	map_list;

	map_list.exit = 0;
	map_list.enemy = 0;
	map_list.exit = 0;
	map_list.objects = 0;
	map_list.player = 0;
	map_list.width = 0;
	map_list.bad_char = 0;
	return (map_list);
}
