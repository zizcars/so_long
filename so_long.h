/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/17 16:16:29 by Achakkaf         ###   ########.fr       */
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

typedef struct s_coor
{
	int x;
	int y;
    char *file;
}	t_coor;

typedef struct s_map_cpy
{
	char **map;
	char **cpy;
} t_map_cpy;

void		error(char *error_message);
t_coor		map_checker(char *filename);
void		check_path(char *filename);
t_map_cpy	map_arr(char *filename, t_coor *coor);
#endif