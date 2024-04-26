CC = cc 
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRC =	mandatory/main.c \
		mandatory/map_checker.c \
		mandatory/map_path.c \
		mandatory/display_map.c \
		mandatory/moves.c 

libs= mylib/mylib.a

OBJ = $(SRC:.c=.o)

%.o: %.c mandatory/so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(libs)
	$(CC) $(CFLAGS) $(OBJ) $(libs) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: 
	@make -C bonus_

$(libs):
	@make -C mylib

clean:
	@make clean -C mylib
	@make clean -C bonus_
	rm -f $(OBJ)

fclean:	clean
	@make fclean -C mylib
	@make fclean -C bonus_
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean
