/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:15 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/19 16:43:05 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_right(t_mlx *mlx)
{
	int x_right;
	int y_right;

	x_right = mlx->x_P - 1;
	y_right = mlx->y_P;
	if (mlx->map[mlx->y_E][mlx->x_E] != 'E')
	{
		mlx->map[mlx->y_E][mlx->x_E] = 'E';
		display_map(mlx);
	}
	if (mlx->map[y_right][x_right] == '0')
	{
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_right][x_right] = 'P';
	}
	else if (mlx->map[y_right][x_right] == 'C')
	{
		mlx->n_C--;
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_right][x_right] = 'P';
	}
	else if (mlx->map[y_right][x_right] == 'E')
	{
		mlx->map[y_right][x_right] = 'P';
		mlx->map[mlx->y_P][mlx->x_P] = '0';
	}
	else
		error("game over\n");
}

void move_left(t_mlx *mlx)
{
	int x_left;
	int y_left;

	x_left = mlx->x_P + 1;
	y_left = mlx->y_P;
	if (mlx->map[mlx->y_E][mlx->x_E] != 'E')
	{
		mlx->map[mlx->y_E][mlx->x_E] = 'E';
		display_map(mlx);
	}
	if (mlx->map[y_left][x_left] == '0')
	{
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_left][x_left] = 'P';
	}
	else if (mlx->map[y_left][x_left] == 'C')
	{
		mlx->n_C--;
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_left][x_left] = 'P';
	}
	else if (mlx->map[y_left][x_left] == 'E')
	{
		mlx->map[y_left][x_left] = 'P';
		mlx->map[mlx->y_P][mlx->x_P] = '0';
	}
	else
		error("game over\n");
}

void move_up(t_mlx *mlx)
{
	int x_up;
	int y_up;

	x_up = mlx->x_P;
	y_up = mlx->y_P - 1;
	if (mlx->map[mlx->y_E][mlx->x_E] != 'E')
	{
		mlx->map[mlx->y_E][mlx->x_E] = 'E';
		display_map(mlx);
	}
	if (mlx->map[y_up][x_up] == '0')
	{
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_up][x_up] = 'P';
	}
	else if (mlx->map[y_up][x_up] == 'C')
	{
		mlx->n_C--;
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_up][x_up] = 'P';
	}
	else if (mlx->map[y_up][x_up] == 'E')
	{
		mlx->map[y_up][x_up] = 'P';
		mlx->map[mlx->y_P][mlx->x_P] = '0';
	}
	else
		error("game over\n");
}

void move_down(t_mlx *mlx)
{
	int x_down;
	int y_down;

	x_down = mlx->x_P;
	y_down = mlx->y_P + 1;
	if (mlx->map[mlx->y_E][mlx->x_E] != 'E')
	{
		mlx->map[mlx->y_E][mlx->x_E] = 'E';
		display_map(mlx);
	}
	if (mlx->map[y_down][x_down] == '0')
	{
		mlx->map[mlx->y_P++][mlx->x_P] = '0';
		mlx->map[y_down][x_down] = 'P';
	}
	else if (mlx->map[y_down][x_down] == 'C')
	{
		mlx->n_C--;
		mlx->map[mlx->y_P][mlx->x_P] = '0';
		mlx->map[y_down][x_down] = 'P';
	}
	else if (mlx->map[y_down][x_down] == 'E')
	{
		mlx->map[y_down][x_down] = 'P';
		mlx->map[mlx->y_P][mlx->x_P] = '0';
	}
	else
		error("game over\n");
}

int moves(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	find_P(mlx, &mlx->x_P, &mlx->y_P, 'P');
	if (keycode == 0)
	{
		move_right(mlx);
		display_map(mlx);
	}
	if (keycode == 1)
	{

		move_down(mlx);
		display_map(mlx);
	}
	if (keycode == 2)
	{
		move_left(mlx);
		display_map(mlx);
	}
	if (keycode == 13)
	{
		move_up(mlx);
		display_map(mlx);
	}
	return (0);
}