CC = cc 
NAME = so_long
BNAME = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
SRC =	mandatory/main.c \
		mandatory/map_checker.c \
		mandatory/map_path.c \
		mandatory/display_map.c \
		mandatory/moves.c 

BSRC =	bonus_/main_bonus.c \
		bonus_/map_checker_bonus.c \
		bonus_/map_path_bonus.c \
		bonus_/display_map_bonus.c \
		bonus_/moves_bonus.c \
		# bonus_/image_bonus.c \

libs= mylib/mylib.a

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

%.o: %.c mandatory/so_long.h  bonus_/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(libs):
	make -C mylib

$(NAME): $(OBJ) $(libs)
	$(CC) $(CFLAGS) $(OBJ)  $(libs) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BOBJ) $(libs)
	$(CC) $(CFLAGS) $(BOBJ)  $(libs) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)


clean:
	make clean -C mylib
	rm -f $(OBJ) $(BOBJ)

fclean:	clean
	make fclean -C mylib
	rm -f $(NAME) $(BNAME)

re:	fclean all
########################################

tests = test.c
TOBJ=$(tests:.c=.o)

test: $(TOBJ)
	$(CC) $(TOBJ) -lmlx -framework OpenGL -framework AppKit 
