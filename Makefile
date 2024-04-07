CC = cc 
NAME = so_long
LIBMLX=mlx/libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
SRC = mandatory/main.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) mlx_lab
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


mlx_lab:
	make -C  mandatory/mlx

clean:
	make clean -C  mandatory/mlx
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OBJ) $(NAME)

re:	fclean all