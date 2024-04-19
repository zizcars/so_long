/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/19 12:58:26 by Achakkaf         ###   ########.fr       */
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

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	char **map;
	char **cpy;
	int size_win_x;
	int size_win_y;
	int size_x;
	int size_y;
	int size_img;
	char *file;
	
} t_mlx;

/*------------------main---------------------*/
void		error(char *error_message);

/*------------------map_checker---------------------*/
int ft_len(char *line);
void count_char(t_count *count, char *line);
void check_char(char *line, int max);
void check_start_end(char *line);
void map_checker(char *filename, t_mlx *mlx);

/*------------------map_path---------------------*/
void *ft_malloc(size_t size);
void map_arr(t_mlx *mlx);
t_position find_P(t_mlx *mlx);
void change_one(t_mlx *mlx, int x, int y);
void check_map(t_mlx *mlx);
void check_path(t_mlx *mlx);

/*------------------map---------------------*/
void create_base(t_mlx *mlx);
void gra_map(t_mlx *mlx);

#endif