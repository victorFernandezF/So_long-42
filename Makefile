# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:38:55 by victofer          #+#    #+#              #
#    Updated: 2023/01/11 10:50:04 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= so_long.out

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
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				window/image.c  \
				window/window.c \
				window/key_management.c \
				moves/left_right_moves.c \
				moves/check_moves.c \
				errors/errors.c  \
				src/main.c


OBJECTS		:= $(SRC:.c=.o)

#COLORS
G = \033[0;32m
R = \033[0;31m
B = \033[0;34m
Y = \033[0;93m
M = \033[0;95m
E = \033[0m
#E COLORSmakecd 

all: nice_text makelibs $(NAME)

nice_text:
	@echo "$(Y)"
	@echo " SSSSS   OOOOO           LL       OOOOO  NN   NN   GGGG "
	@echo "SS      OO   OO          LL      OO   OO NNN  NN  GG  GG "
	@echo " SSSSS  OO   OO          LL      OO   OO NN N NN GG  "
	@echo "     SS OO   OO          LL      OO   OO NN  NNN GG   GG"
	@echo " SSSSS   OOOO0  _______  LLLLLLL  OOOO0  NN   NN  GGGGGG "
	@echo "               |_______| "
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
	@rm -rf a.out

re: fclean all

.SILENT: $(OBJS)
.PHONY: clean fclean all re