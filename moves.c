/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:15 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/20 13:02:50 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_right(t_mlx *mlx)
{
	int x_right;
	int y_right;

	x_right = mlx->x_p - 1;
	y_right = mlx->y_p;
	if (mlx->map[y_right][x_right] == '0')
	{
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_right][x_right] = 'P';
	}
	else if (mlx->map[y_right][x_right] == 'C')
	{
		mlx->n_c--;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_right][x_right] = 'P';
	}
	else if (mlx->map[y_right][x_right] == 'E')
	{
		if (mlx->n_c == 0)
			exit(0);
		mlx->map[y_right][x_right] = 'P';
		mlx->map[mlx->y_p][mlx->x_p] = '0';
	}
	else
		error("game over\n");
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
}

void move_left(t_mlx *mlx)
{
	int x_left;
	int y_left;

	x_left = mlx->x_p + 1;
	y_left = mlx->y_p;

	if (mlx->map[y_left][x_left] == '0')
	{
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_left][x_left] = 'P';
	}
	else if (mlx->map[y_left][x_left] == 'C')
	{
		mlx->n_c--;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_left][x_left] = 'P';
	}
	else if (mlx->map[y_left][x_left] == 'E')
	{
		if (mlx->n_c == 0)
			exit(0);
		mlx->map[y_left][x_left] = 'P';
		mlx->map[mlx->y_p][mlx->x_p] = '0';
	}
	else
		error("game over\n");
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
}

void move_up(t_mlx *mlx)
{
	int x_up;
	int y_up;

	x_up = mlx->x_p;
	y_up = mlx->y_p - 1;

	if (mlx->map[y_up][x_up] == '0')
	{
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_up][x_up] = 'P';
	}
	else if (mlx->map[y_up][x_up] == 'C')
	{
		mlx->n_c--;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_up][x_up] = 'P';
	}
	else if (mlx->map[y_up][x_up] == 'E')
	{
		if (mlx->n_c == 0)
			exit(0);
		mlx->map[y_up][x_up] = 'P';
		mlx->map[mlx->y_p][mlx->x_p] = '0';
	}
	else
		error("game over\n");
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
}

void move_down(t_mlx *mlx)
{
	int x_down;
	int y_down;

	x_down = mlx->x_p;
	y_down = mlx->y_p + 1;
	if (mlx->map[y_down][x_down] == '0')
	{
		mlx->map[mlx->y_p++][mlx->x_p] = '0';
		mlx->map[y_down][x_down] = 'P';
	}
	else if (mlx->map[y_down][x_down] == 'C')
	{
		mlx->n_c--;
		mlx->map[mlx->y_p][mlx->x_p] = '0';
		mlx->map[y_down][x_down] = 'P';
	}
	else if (mlx->map[y_down][x_down] == 'E')
	{
		if (mlx->n_c == 0)
			exit(0);
		mlx->map[y_down][x_down] = 'P';
		mlx->map[mlx->y_p][mlx->x_p] = '0';
	}
	else
		error("game over\n");
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
}

int moves(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	find_P(mlx, &mlx->x_p, &mlx->y_p, 'P');
	if (keycode == 0 || keycode == 123)
	{
		mlx->moves++;
		move_right(mlx);
		display_map(mlx);
		ft_printf("moves:%d\n", mlx->moves);
	}
	else if (keycode == 1 || keycode == 125)
	{
		mlx->moves++;
		move_down(mlx);
		display_map(mlx);
		ft_printf("moves:%d\n", mlx->moves);
	}
	else if (keycode == 2 || keycode == 124)
	{
		mlx->moves++;
		move_left(mlx);
		display_map(mlx);
		ft_printf("moves:%d\n", mlx->moves);
	}
	else if (keycode == 13 || keycode == 126)
	{
		mlx->moves++;
		move_up(mlx);
		display_map(mlx);
		ft_printf("moves:%d\n", mlx->moves);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}