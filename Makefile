CC = cc 
NAME = so_long
# BNAME = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
SRC =	mandatory/main.c \
		mandatory/map_checker.c \
		mandatory/map_path.c \
		mandatory/display_map.c \
		mandatory/moves.c 

# BSRC =	bonus_/main_bonus.c \
# 		bonus_/map_checker_bonus.c \
# 		bonus_/map_path_bonus.c \
# 		bonus_/display_map_bonus.c \
# 		bonus_/moves_bonus.c \
# 		# bonus_/image_bonus.c \

libs= mylib/mylib.a

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

%.o: %.c mandatory/so_long.h  bonus_/so_long_bonus.h
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
