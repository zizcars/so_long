CC = cc 
BNAME = so_long
CFLAGS = -Wall -Wextra -Werror
BSRC =	main_bonus.c \
		map_checker_bonus.c \
		map_path_bonus.c \
		display_map_bonus.c \
		moves_bonus.c \
		image_bonus.c 

libs= ../mylib/mylib.a
BOBJ = $(BSRC:.c=.o)

%.o: %.c mandatory/so_long.h  bonus_/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: ../$(BNAME)

../$(BNAME): $(BOBJ) $(libs)
	$(CC) $(CFLAGS) $(BOBJ) $(libs) -lmlx -framework OpenGL -framework AppKit -o ../$(BNAME)

$(libs):
	@make -C ../mylib

clean:
	rm -f $(BOBJ)

fclean:	clean
	rm -f ../$(BNAME)

re:	fclean all

.PHONY: clean fclean