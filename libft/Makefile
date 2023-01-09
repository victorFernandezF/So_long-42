# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 09:36:58 by victofer          #+#    #+#              #
#    Updated: 2022/12/12 10:27:57 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC=gcc
NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_split.c max.c min.c ft_pow.c\
	ft_printf.c ft_print_c_str_int.c ft_print_unsigned.c ft_print_hexa.c ft_print_ptr.c \
	ft_put_hexa.c ft_put_bin.c ft_put_oct.c ft_str_rev.c ft_change_bases.c \
	
OBJ= $(SRC:.c=.o)
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ =$(BONUS:.c=.o) 

# - COLOURS - 
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW = \033[0;93m
MAGENTA = \033[0;95m
END=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@rm -rf *.gch
	@rm -rf *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all	

every: all bonus

revery: fclean all bonus

.SILENT: $(OBJS)
.PHONY: clean fclean all re bonus
