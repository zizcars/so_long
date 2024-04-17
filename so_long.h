/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/17 11:11:21 by Achakkaf         ###   ########.fr       */
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
}	t_coor;

void	error(char *error_message);
void	check_char(char *str, int x);
t_coor  map_arr(char *file_name);
#endif