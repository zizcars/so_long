/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:54:44 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/22 18:01:43 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		error("out of memory error");
	return (p);
}

void	find_p(t_mlx *mlx, int *x, int *y, char c)
{
	*y = 0;
	while (*y < mlx->size_y)
	{
		*x = 0;
		while (*x < mlx->size_x)
		{
			if (mlx->map[*y][*x] == c)
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	change_one(t_mlx *mlx, int x, int y)
{
	if (mlx->cpy[y][x] == '1' || (0 > x \
		|| x > mlx->size_x) || (mlx->size_y < y || y < 0))
		return ;
	else
		mlx->cpy[y][x] = '1';
	change_one(mlx, x + 1, y);
	change_one(mlx, x - 1, y);
	change_one(mlx, x, y + 1);
	change_one(mlx, x, y - 1);
}

void	check_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			if (mlx->cpy[y][x] == 'P' \
				|| mlx->cpy[y][x] == 'C' || mlx->cpy[y][x] == 'E')
				error("No path found\n");
			x++;
		}
		y++;
	}
}

void	check_path(t_mlx *mlx)
{
	int	x;
	int	y;

	find_p(mlx, &x, &y, 'P');
	change_one(mlx, x, y);
	check_map(mlx);
}
