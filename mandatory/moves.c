/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:15 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/22 18:01:58 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_e(t_mlx *mlx)
{
	if (mlx->map[mlx->y_e][mlx->x_e] == '0')
		mlx->map[mlx->y_e][mlx->x_e] = 'E';
	display_map(mlx);
	ft_printf("moves:%d\n", mlx->moves);
}

void	move_(t_mlx *mlx, int x, int y)
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
		return ;
	check_e(mlx);
}

int	moves(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	find_p(mlx, &mlx->x_p, &mlx->y_p, 'P');
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
