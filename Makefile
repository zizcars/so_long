CC = cc 
NAME = so_long
CFLAGS = -Wall -Wextra -Werror 
SRC =	main.c \
		map_functions.c
libs= mylib/mylib.a

OBJ = $(SRC:.c=.o)

%.o: %.c so_long.h
	$(CC) -Imlx -c $< -o $@

all: $(NAME)

$(libs):
	make -C mylib

$(NAME): $(OBJ) $(libs)
	$(CC) $(OBJ) $(libs) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

tests = test.c
TOBJ=$(tests:.c=.o)

test: $(TOBJ)
	$(CC) $(TOBJ) -lmlx -framework OpenGL -framework AppKit 

clean:
	make clean -C mylib
	rm -f $(OBJ)

fclean:	clean
	make fclean -C mylib
	rm -f $(OBJ) $(NAME)

re:	fclean all