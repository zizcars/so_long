/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:15 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/26 15:12:52 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_n_p1(t_mlx *mlx, int y)
{
	if (mlx->map[mlx->y_n][mlx->x_n] == '0')
	{
		mlx->map[mlx->y_n][mlx->x_n] = 'N';
		mlx->map[y][mlx->x_n] = '0';
	}
	else if (mlx->map[mlx->y_n][mlx->x_n] == 'C')
	{
		mlx->in_c = 1;
		mlx->x_c = mlx->x_n;
		mlx->y_c = mlx->y_n;
		mlx->map[y][mlx->x_n] = '0';
		mlx->map[mlx->y_n][mlx->x_n] = 'N';
	}
	else if (mlx->map[mlx->y_n][mlx->x_n] == 'E')
	{
		mlx->map[y][mlx->x_n] = '0';
		mlx->map[mlx->y_n][mlx->x_n] = 'N';
	}
	else if (mlx->map[mlx->y_n][mlx->x_n] == 'P')
		error("Game over\n");
	else
		return ;
}

void	move_n(t_mlx *mlx)
{
	int	y;

	y = mlx->y_n;
	if (mlx->map[mlx->y_n + 1][mlx->x_n] == '1' \
		|| mlx->map[mlx->y_n - 1][mlx->x_n] == '1')
	{
		if (mlx->up_down == 1)
			mlx->up_down = -1;
		else
			mlx->up_down = 1;
	}
	if (mlx->up_down == 1)
		mlx->y_n++;
	else if (mlx->up_down == -1)
		mlx->y_n--;
	move_n_p1(mlx, y);
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
	if (mlx->in_c && mlx->map[mlx->y_c][mlx->x_c] == '0')
	{
		mlx->map[mlx->y_c][mlx->x_c] = 'C';
		mlx->in_c = 0;
	}
}

void	check_e(t_mlx *mlx)
{
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
}

void	check_wall(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == '1')
		return ;
	else
		error("Game over\n");
}

void	move_(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == '0')
	{
		mlx->moves++;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y][x] = 'P';
	}
	else if (mlx->map[y][x] == 'C')
	{
		mlx->moves++;
		mlx->n_c--;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y][x] = 'P';
	}
	else if (mlx->map[y][x] == 'E')
	{
		if (mlx->n_c == 0)
			exit(0);
		mlx->moves++;
		mlx->map[y][x] = 'P';
		mlx->map[mlx->y_p][mlx->x_p] = '0';
	}
	else 
		check_wall(mlx, x, y);
	check_e(mlx);
	display_map(mlx);
}
