/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/20 12:59:45 by Achakkaf         ###   ########.fr       */
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

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img[5];
	char **map;
	char **cpy;
	int size_win_x;
	int size_win_y;
	int size_x;
	int size_y;
	int size_img;
	char *file;
	int n_c;
	int n_p;
	int n_e;
	int x_p;
	int y_p;
	int x_e;
	int y_e;
	int moves;
} t_mlx;

/*------------------main---------------------*/
/// @brief print error  in stderr and exit with 1
/// @param error_message
void	error(char *error_message);

/// @brief convert from string to 2D array
/// @param mlx
void	create_map(t_mlx *mlx);
/*------------------map_checker---------------------*/
int ft_len(char *line);
void count_char(t_mlx *mlx, char *line);
void check_char(char *line, int max);
void check_start_end(char *line);
void map_checker(char *filename, t_mlx *mlx);

/*------------------map_path---------------------*/
void *ft_malloc(size_t size);
void map_arr(t_mlx *mlx);
void	find_P(t_mlx *mlx, int *x, int *y, char c);
void change_one(t_mlx *mlx, int x, int y);
void check_map(t_mlx *mlx);
void check_path(t_mlx *mlx);

/*------------------map---------------------*/
void create_base(t_mlx *mlx);
void display_map(t_mlx *mlx);

/*------------------moves---------------------*/
void move_right(t_mlx *mlx);
int moves(int keycode, void *param);

/*------------------image.c---------------------*/
/// @brief set img to it default values
/// @param mlx 
void mlx_img(t_mlx *mlx);

#endif