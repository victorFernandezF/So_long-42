/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:28:53 by victofer          #+#    #+#             */
/*   Updated: 2023/01/10 12:09:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

// -------------- M A C R O S --------------------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

// --------------- S T R U C T S -------------------

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/* Windows stuff */
typedef struct s_window {
	void		*reference;
	t_vector	size;
	char		*name;
}				t_window;

/* Images stuff */
typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

/* Map stuff */
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

typedef struct s_game
{
	char		*map_file;
	void		*mlx;
	int			collect;
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

// ------------ F U N C T I O N S ---------------------

t_image		ft_new_sprite(void *mlx, char *path);
int			key_hook(int keycode, t_game *game);

	// GET NEXT LINE 
char		*get_next_line(int fd);
char		*ft_read(int fd, char *str);
char		*get_line_gnl(char *str);
char		*save_rest(char *str);
char		*ft_join_free(char *buffer, char *buff);
char		*ft_strjoin_gnl(char *s1, char *s2);
size_t		ft_strlen_gnl(char *s);
char		*ft_strchr_gnl(char *s, int c);
void		*ft_calloc_gnl(size_t count, size_t size);

	// ERRORS MANAGEMENT
void		ft_error(char *msg);
void		ft_error_free(char *msg, t_map map_list);
void		ft_error_destroy(char *msg, t_game game);

	//FREE STUFF
void		ft_free_map(t_map map_list);

	// MAP CHECKER 
int			check_args(int n, char *str);
int			check_map_number_items(t_map map_list);
t_map		check_map_items(t_map map_list);
t_map		check_map(t_map map_list);
int			check_ber_file(char *str);
int			check_first_line(char *str, t_map map_list);
int			check_last_line(char *str, t_map map_list);
int			check_middle_lines(char *str, t_map map_list);
int			check_map_not_sqare(t_map map_list);

	//MAP READER
int			count_map_lines(char *file);
char		**malloc_cols(char *file);
char		**map_reader(char *file, t_map map_list);

	// GAME
t_map		map_list_init(void);
t_game		game_start(t_game game);
t_game		load_images(t_game game);
t_game		open_window(t_game game);
t_game		draw_map(t_game game, char **map, void *player, t_vector img_pos);

	//MOVES
t_game		right_move(t_game game, char **map, t_vector img_pos);
t_game		left_move(t_game game, char **map, t_vector img_pos);
t_game		up_move(t_game game, char **map, t_vector img_pos);
t_game		down_move(t_game game, char **map, t_vector img_pos);

	// TESTING
void		show_leaks(void);

t_game		destroy_aux(char map, t_game game);
t_game		ft_destroy_map(t_game game, char **map);
t_game		check_door(t_game game);
t_game		check_everything(t_game game, int i, int j, char **map);
void		finish_game(t_game game);


#endif