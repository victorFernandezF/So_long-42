#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

G=\033[0;32m
R=\033[0;31m
B=\033[0;34m
Y= \033[0;93m
M= \033[0;95m
X=\033[0m

%.o : %.c
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
	
%.o : %.m
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@ar rcs $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

fclean: clean
	@rm -f $(NAME) *~
	@rm -f mlx_app

.SILENT: all
re: clean all
