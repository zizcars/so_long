/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/22 18:01:31 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "../mylib/ft_printf.h"
# include "../mylib/libft.h"
# include "../mylib/get_next_line.h"
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
}	t_mlx;

/*----------------------main----------------------*/
void	error(char *error_message);
void	create_map(t_mlx *mlx);

/*------------------map_checker-------------------*/
int		ft_len(char *line);
void	count_char(t_mlx *mlx, char *line);
void	check_char(char *line, int max);
void	check_start_end(char *line);
void	map_reader(t_mlx *mlx, int fd);
void	map_checker(char *filename, t_mlx *mlx);

/*------------------map_path----------------------*/
void	*ft_malloc(size_t size);
void	find_p(t_mlx *mlx, int *x, int *y, char c);
void	change_one(t_mlx *mlx, int x, int y);
void	check_map(t_mlx *mlx);
void	check_path(t_mlx *mlx);

/*------------------display_map------------------*/
void	mlx_img(t_mlx *mlx);
void	display_ground(t_mlx *mlx);
void	display_map(t_mlx *mlx);

/*---------------------moves---------------------*/
void	move_(t_mlx *mlx, int x, int y);
int		moves(int keycode, void *param);

#endif