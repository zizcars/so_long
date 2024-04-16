/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:45 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/16 14:17:12 by Achakkaf         ###   ########.fr       */
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

void	error(char *error_message);
void	map_arr(char *file_name);
void	check_char(char *str, int x);
#endif