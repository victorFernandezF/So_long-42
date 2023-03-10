/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:28:53 by victofer          #+#    #+#             */
/*   Updated: 2023/01/16 13:51:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "./structs.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

	// GET NEXT LINE AND ITS UTILS
char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*get_line_gnl(char *str);
char	*save_rest(char *str);
char	*ft_join_free(char *buffer, char *buff);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_calloc_gnl(size_t count, size_t size);

	// ERRORS MANAGEMENT
void	ft_error(char *msg);
void	ft_error_free(char *msg, t_map map_list);
void	ft_error_destroy(char *msg, t_game game);

	//FREE STUFF
void	ft_free_map(t_map map_list);

	// MAP CHECKER (BEFORE STARTING THE GAME)
int		check_args(int n, char *str);
int		check_map_number_items(t_map map_list);
t_map	check_map_items(t_map map_list);
t_map	check_map(t_map map_list);
int		check_ber_file(char *str);
int		check_first_line(char *str, t_map map_list);
int		check_last_line(char *str, t_map map_list);
int		check_middle_lines(char *str, t_map map_list);
int		check_map_not_sqare(t_map map_list);

	//MAP READER
int		count_map_lines(char *file);
char	**malloc_cols(char *file);
char	**map_reader(char *file, t_map map_list);

	// IMAGES
t_game	load_images(t_game game);
t_image	ft_new_sprite(void *mlx, char *path);

	// GAME START AND MAP DRAWING
t_map	map_list_init(void);
t_game	game_start(t_game game);
t_game	open_window(t_game game);
t_game	draw_map(t_game game, char **map, void *player, t_vector img_pos);
t_game	draw_aux(char map, t_game game, void *player, t_vector img_pos);

	//KEY MANAGEMENT
int		key_management(int keycode, t_game *game);
t_game	print_moves(t_game game);

	// MOVES
t_game	right_move(t_game game, char **map, t_vector img_pos, int i);
t_game	left_move(t_game game, char **map, t_vector img_pos, int i);
t_game	up_move(t_game game, char **map, t_vector img_pos, int i);
t_game	down_move(t_game game, char **map, t_vector img_pos, int i);
t_game	last_map(t_game game, char **map, void *player, t_vector img_pos);

	// MOVES CHECKER 
t_game	check_door(t_game game);
t_game	is_game_over(t_game game, char **map, void *player, t_vector img_pos);
int		chek_open_door(int i, int j, int dir, t_game game);
int		check_player_wall(char c1, char c2);

	// GAME FINISHER
int		end_game(t_game *game);
void	game_over(t_game game);
t_image	get_game_objects(t_game game);

	// BONUS
t_game	game_start_bonus(t_game game);
t_game	check_chars_move(t_game game, char c);
int		key_management_bonus(int keycode, t_game *game);
t_map	check_map_items_bonus(t_map map_list, int i);
t_map	check_map_bonus(t_map map_list);
t_game	draw_map_bonus(t_game game, char **map, void *player, t_vector img_pos);
t_game	draw_aux_bonus(char map, t_game game, void *player, t_vector img_pos);
t_game	open_window_bonus(t_game game);
t_game	last_map_bonus(t_game game, char **map, void *player, t_vector img_pos);
int		chek_enemy(int i, int j, int dir, t_game game);
int		end_game_bonus(t_game *game);
void	game_over_b(t_game game);
t_game	put_string_moves(t_game g);
t_game	right_move_bonus(t_game game, char **map, t_vector pos, int i);
t_game	left_move_bonus(t_game game, char **map, t_vector pos, int i);
t_game	up_move_bonus(t_game game, char **map, t_vector img_pos, int i);
t_game	down_move_bonus(t_game game, char **map, t_vector img_pos, int i);
t_game	is_game_over_b(t_game game, char **map, void *player, t_vector img_pos);
int		check_player_wall_bonus(char c1, char c2);

#endif