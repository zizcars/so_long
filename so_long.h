/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/18 16:15:01 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <math.h>
#include <fcntl.h>
#include <mlx.h>
#include "mylib/ft_printf.h"
#include "mylib/libft.h"
#include "mylib/get_next_line.h"
#include <stdlib.h>

#define STDERR 0
#define SIZE 32
typedef struct s_count
{
	int n_C;
	int n_P;
	int n_E;
} t_count;

typedef struct s_position
{
	int x;
	int y;
}	t_position;

// typedef struct s_map_cpy
// {
// 	char **map;
// 	char **cpy;
// } t_map_cpy;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	char **map;
	char **cpy;
	// int x_win;
	// int y_win;
	int size_win_x;
	int size_win_y;
	int size_img;
	char *file;
	
} t_mlx;

void		error(char *error_message);
t_mlx		map_checker(char *filename);
void		check_path(char *filename);
t_mlx		map_arr(char *filename, t_mlx *coor);
int			ft_len(char *line);
void		gra_map(t_mlx *map, t_mlx *mlx, t_mlx *coor);
void		create_bas(char *filename, t_mlx *map, t_mlx *mlx, t_mlx *coor);

#endif