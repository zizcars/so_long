/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/20 15:42:35 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "mylib/ft_printf.h"
# include "mylib/libft.h"
# include "mylib/get_next_line.h"
# include <stdlib.h>

# define STDERR 0
# define A 0
# define S 1
# define D 2
# define W 13
# define L_ARROW 123
# define R_ARROW 124
# define D_ARROW 125
# define U_ARROW 126

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img[5];
	char	**map;
	char	**cpy;
	int		size_win_x;
	int		size_win_y;
	int		size_x;
	int		size_y;
	int		size_img;
	char	*file;
	int		n_c;
	int		n_p;
	int		n_e;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		moves;
} t_mlx;

/*------------------main---------------------*/
/// @brief print error  in stderr and exit with 1
/// @param error_message
void	error(char *error_message);

/// @brief convert from string to 2D array
/// @param mlx
void	create_map(t_mlx *mlx);

/*------------------map_checker---------------------*/
/// @brief length of a line (end with /n or \0) 
/// @param line 
/// @return length
int		ft_len(char *line);

/// @brief count who many C E P in a line
/// @param count place to store C E P
/// @param line 
void	count_char(t_mlx *mlx, char *line);

/// @brief check if the line is valid
/// @param line 
/// @param max 
void	check_char(char *line, int max);

/// @brief check if first line and last line all ones
/// @param line
void	check_start_end(char *line);

/// @brief read map from a file
/// @param mlx 
/// @param fd 
void	map_reader(t_mlx *mlx, int fd);

/// @brief check the map is valid or not and calculte the size of map and store it in file variable
/// @param filename 
/// @param mlx 
void	map_checker(char *filename, t_mlx *mlx);

/*------------------map_path---------------------*/
/// @brief allocate memory and protacte your allocation if it field
/// @param size
/// @return the address of allocation
void	*ft_malloc(size_t size);

/// @brief find coordonate of char in 2D array
/// @param mlx 
/// @param x place to store x 
/// @param y place to store y 
/// @param c character to search for it coordonate
void	find_P(t_mlx *mlx, int *x, int *y, char c);

/// @brief change the cpy of map to 1
/// @param mlx
/// @param x of player
/// @param y of player
void	change_one(t_mlx *mlx, int x, int y);

/// @brief search for P or C or E
/// @param mlx
void	check_map(t_mlx *mlx);

/// @brief check if the path is valid or not
/// @param mlx
void	check_path(t_mlx *mlx);

/*------------------display_map---------------------*/
/// @brief set imges variable to it default values
/// @param mlx 
void	mlx_img(t_mlx *mlx);

/// @brief display ground
/// @param mlx 
void	display_ground(t_mlx *mlx);

/// @brief display map
/// @param mlx 
void	display_map(t_mlx *mlx);

/*------------------moves---------------------*/
/// @brief move char to (x , y)
/// @param mlx 
/// @param x 
/// @param y 
void	move_(t_mlx *mlx, int x, int y);

/// @brief move char up, down, right, left
/// @param keycode 
/// @param param mlx
/// @return 
int		moves(int keycode, void *param);

#endif