/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:54:44 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/19 12:50:50 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief allocate memory and protacte your allocation
/// @param size 
/// @return the address of allocation
void *ft_malloc(size_t size)
{
    void *p;

	p = malloc(size);
    if (!p)
        error("out of memory error");
    return (p);
}

/// @brief find p in map
/// @param mlx 
/// @return coordonte of the P in map
t_position	find_P(t_mlx *mlx)
{
	t_position c_position;

	c_position.y = 0;
	while (c_position.y < mlx->size_y)
	{	
		c_position.x = 0;
		while(c_position.x < mlx->size_x)
		{
			if (mlx->map[c_position.y][c_position.x] == 'P')
				return (c_position);
			c_position.x++;
		}
		c_position.y++;
	}
	return (c_position);
}

/// @brief change the cpy of map to 1
/// @param mlx 
/// @param x
/// @param y 
void change_one(t_mlx *mlx, int x, int y)
{
	if (mlx->cpy[y][x] == '1' || ( 0 > x || x > mlx->size_x) || (mlx->size_y < y || y < 0))
		return;
	else
		mlx->cpy[y][x] = '1';
	change_one(mlx, x + 1, y);
	change_one(mlx, x - 1, y);
	change_one(mlx, x, y + 1);
	change_one(mlx, x, y - 1);
}

/// @brief search for P or C or E
/// @param mlx 
void check_map(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			if (mlx->cpy[y][x] == 'P' || mlx->cpy[y][x] == 'C' || mlx->cpy[y][x] == 'E')
				error("No path found\n");
			x++;
		}
		y++;
	}
}

/// @brief check if the path is valid or not
/// @param mlx 
void check_path(t_mlx *mlx)
{
	t_position place_P;

	place_P = find_P(mlx);
	change_one(mlx, place_P.x, place_P.y);
	check_map(mlx);
}
