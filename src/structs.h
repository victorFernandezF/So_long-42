/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:26:18 by victofer          #+#    #+#             */
/*   Updated: 2023/01/13 10:58:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "./so_long.h"

// -------------- C O L O R S ------------------

# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"

// ---------------- K E Y S --------------------
enum e_keys
{
	KA = 0,
	KS = 1,
	KD = 2,
	KW = 13,
	KLEFT = 123,
	KRIGHT = 124,
	KDOWN = 125,
	KUP = 126,
	KESC = 53
};

// ------------- S T R U C T S -----------------

// struct with an 'x' and 'y' used for positions
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

// Struct with the WINDOW datas
typedef struct s_window {
	void		*reference;
	t_vector	size;
	char		*name;
}				t_window;

// Struct with the IMAGE datas
typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

// Struct with the MAP datas
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

// Struct with the GAME datas
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
	t_image		pokeball;
	t_image		superball;
	t_image		ultraball;
	t_image		masterball;
	t_image		player_right;
	t_image		player_down;
	t_image		player_up;
	t_image		player_left;
	t_vector	wall_position;	
}				t_game;

#endif
