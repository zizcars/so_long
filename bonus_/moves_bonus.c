/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:15 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/22 18:35:18 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void move_n(t_mlx *mlx)
{
	int y;

	y = mlx->y_n;
	if (mlx->map[mlx->y_n + 1][mlx->x_n] == '1' || mlx->map[mlx->y_n - 1][mlx->x_n] == '1')
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
	else
		return;
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
	if (mlx->in_c && mlx->map[mlx->y_c][mlx->x_c] == '0')
	{
		mlx->map[mlx->y_c][mlx->x_c] = 'C';
		mlx->in_c = 0;
	}
}

void move_(t_mlx *mlx, int x, int y)
{
	mlx->moves++;
	if (mlx->map[y][x] == '0')
	{
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y][x] = 'P';
	}
	else if (mlx->map[y][x] == 'C')
	{
		mlx->n_c--;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y][x] = 'P';
	}
	else if (mlx->map[y][x] == 'E')
	{
		if (mlx->n_c == 0)
			exit(0);
		mlx->map[y][x] = 'P';
		mlx->map[mlx->y_p][mlx->x_p] = '0';
	}
	else if (mlx->map[y][x] == '1')
		return;
	else
		error("Game over\n");
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
	move_n(mlx);
	// display_map(mlx);
}

int moves(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	find_P(mlx, &mlx->x_p, &mlx->y_p, 'P');
	if (keycode == A || keycode == L_ARROW)
		move_(mlx, mlx->x_p - 1, mlx->y_p);
	else if (keycode == S || keycode == D_ARROW)
		move_(mlx, mlx->x_p, mlx->y_p + 1);
	else if (keycode == D || keycode == R_ARROW)
		move_(mlx, mlx->x_p + 1, mlx->y_p);
	else if (keycode == W || keycode == U_ARROW)
		move_(mlx, mlx->x_p, mlx->y_p - 1);
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}
