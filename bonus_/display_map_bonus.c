/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/26 15:19:07 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_ground(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			mlx_put_image_to_window(mlx->mlx, \
				mlx->win, mlx->img[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	display_condition(t_mlx *mlx, int *x, int y, int *i)
{
	if ((mlx->map)[y][*x] == '1')
		*i = 1;
	else if ((mlx->map)[y][*x] == 'P')
		*i = 2;
	else if ((mlx->map)[y][*x] == 'E')
	{
		if (mlx->n_c == 0)
			*i = 4;
		else
			*i = 3;
	}
	else
	{
		(*x)++;
		return (0);
	}
	return (1);
}

void	display_row(t_mlx *mlx, int y)
{
	int		x;
	int		i;
	char	*tmp;

	x = 0;
	while (x < mlx->size_x)
	{
		if (display_condition(mlx, &x, y, &i))
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, \
				mlx->img[i], x * 64, y * 64);
			tmp = ft_itoa(mlx->moves);
			mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF, tmp);
			free(tmp);
			tmp = NULL;
			x++;
		}
	}
}

int	display_map(void *param)
{
	int		y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	display_ground(mlx);
	while (y < mlx->size_y)
	{
		display_row(mlx, y);
		y++;
	}
	coin_animation(mlx);
	return (0);
}
