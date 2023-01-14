# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:38:55 by victofer          #+#    #+#              #
#    Updated: 2023/01/14 11:38:26 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= so_long.out
NAMEBONUS	:= so_long_bonus.out

LIBFT_PATH	:= ./libft/ 
LIBFT_LIB	:= $(LIBFT_PATH)libft.a
MLX_PATH	:= ./mlx/
MLX_LIB		:= $(MLX_PATH)libmlx.a
MLX_FLAGS	:= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC			:=  testing_stuff/leaks.c \
				map_files/map_reader.c \
				map_files/map_checker.c \
				map_files/map_lines_checker.c \
				map_files/init.c \
				map_files/draw_map.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				window/image.c  \
				window/window.c \
				window/key_management.c \
				moves/moves.c \
				moves/check_moves.c \
				errors/errors.c  \
				src/main.c

SRC_BONUS	:=  testing_stuff/leaks.c \
				bonus/* \
				map_files/map_reader.c \
				map_files/map_checker.c \
				map_files/map_lines_checker.c \
				map_files/init.c \
				map_files/draw_map.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				window/image.c  \
				window/window.c \
				window/key_management.c \
				moves/moves.c \
				moves/check_moves.c \
				errors/errors.c  \

OBJECTS		:= $(SRC:.c=.o)
OBJECTS_B	:= $(SRC_BONUS:.c=.o)

#COLORS
G = \033[0;32m
R = \033[0;31m
B = \033[0;34m
Y = \033[0;93m
M = \033[0;95m
E = \033[0m
#E COLORSmakecd 

all: nice_text makelibs $(NAME)

bonus: makelibs $(NAMEBONUS)

nice_text:
	@echo "$(Y)"
	@echo " SSSSS  1111111             LL      1111111 NN   NN   GGGG "
	@echo "SS      10   01             LL      1O   O1 NNN  NN  GG  GG "
	@echo " SSSSS  10   O1             LL      1O   O1 NN N NN GG  "
	@echo "     SS 10   01             LL      1O   O1 NN  NNN GG   GG"
	@echo " SSSSS  1111111 __________  LLLLLLL 1111111 NN   NN  GGGGGG "
	@echo "               |          |"
	@echo "               | victofer |"
	@echo "               |__________|"
	@echo "$(E)"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -C $(SRC)

makelibs:
	@echo ""
	@echo "$(Y)0------ COMPILING LIBS -------0$(E)"
	@make -C $(MLX_PATH) all
	@echo "$(Y)|     $(G)Minilibx compiled 😀    $(Y)|"
	@make -C $(LIBFT_PATH) all
	@echo "$(Y)|       $(G)Libft compiled 😀     $(Y)|"
	@echo "$(Y)0-----------------------------0 $(E)"
	@echo "$(E)"
	

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) libft/libft.a -o so_long 
	@echo "   $(Y)0-----------------------0"
	@echo "   $(Y)|$(G)  So_long Created 😁  $(Y) |"
	@echo "   $(Y)0-----------------------0"
	@echo "$(E)"

$(NAMEBONUS): $(OBJECTS_B)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS_B) $(MLX_LIB) libft/libft.a -o so_long_bonus
	@echo "$(Y)0-----------------------------0"
	@echo "$(Y)|$(G)  So_long_bonus Created 😁  $(Y) |"
	@echo "$(Y)0-----------------------------0"
	@echo "$(E)"



clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJECTS)
	@echo ""
	@echo "$(Y)0------------------------0"
	@echo "$(Y)|$(M)  Everything cleaned 👍$(Y) |"
	@echo "$(Y)0------------------------0"
	@echo "$(E)"

fclean: clean
	@make -C $(MLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@rm -rf so_long
	@rm -rf so_long_bonus
	@rm -rf a.out

re: fclean all

.SILENT: $(OBJS)
.PHONY: clean fclean all re