/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:26:18 by victofer          #+#    #+#             */
/*   Updated: 2023/01/12 11:27:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "./so_long.h"

// --------------- S T R U C T S -------------------

// struct with an x and y used for positions
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

// Window datas
typedef struct s_window {
	void		*reference;
	t_vector	size;
	char		*name;
}				t_window;

// Images datas
typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

// Map datas
typedef struct s_map
{
	int		width;
	int		height;
	int		player;
	int		objects;
	int		exit;
	int		bad_char;
	char	**map;
}			t_map;

// game datas
typedef struct s_game
{
	char		*map_file;
	void		*mlx;
	int			collect;
	int			moves;
	int			flag;
	int			is_finish;
	char		**og_map;
	t_map		map;
	t_window	win;
	t_image		wall;
	t_image		floor;
	t_image		door;
	t_image		door_open;
	t_image		object;
	t_image		player_right;
	t_image		player_down;
	t_image		player_up;
	t_image		player_left;
	t_vector	wall_position;	
}				t_game;

#endif
