/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/24 13:11:50 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void coin_imgs(t_mlx *mlx)
{
	int i;

	mlx->coin_frames[0] = "textures/coin/coin0.xpm";
	mlx->coin_frames[1] = "textures/coin/coin1.xpm";
	mlx->coin_frames[2] = "textures/coin/coin2.xpm";
	mlx->coin_frames[3] = "textures/coin/coin3.xpm";
	mlx->coin_frames[4] = "textures/coin/coin4.xpm";
	mlx->coin_frames[5] = "textures/coin/coin5.xpm";
	mlx->coin_frames[6] = "textures/coin/coin6.xpm";
	i = 0;
	while (i < 7)
	{
		mlx->coin_img[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->coin_frames[i], &mlx->size_img, &mlx->size_img);
		if (mlx->coin_img[i] == NULL)
		{
			write(2, "coin Error\n", 12);
			exit(1);
		}
		i++;
	}
}

void mlx_img(t_mlx *mlx)
{
	char	*frames[6];
	int		i;

	i = 0;
	frames[0] = "textures/ground.xpm";
	frames[1] = "textures/wall.xpm";
	frames[2] = "textures/player.xpm";
	frames[3] = "textures/exit0.xpm";
	frames[4] = "textures/exit1.xpm";
	frames[5] = "textures/enemy.xpm";
	while (i < 6)
	{
		mlx->img[i] = mlx_xpm_file_to_image(mlx->mlx, frames[i], &mlx->size_img, &mlx->size_img);
		if (mlx->img[i] == NULL)
			error("invalid image\n");
		i++;
	}
}

void display_ground(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void display_coin(t_mlx *mlx, int x, int y)
{
	char *tmp;

	mlx->index++;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->coin_img[(mlx->index % 70) / 10], x * 64, y * 64);
	tmp = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF, tmp);
	free(tmp);
	tmp = NULL;
}

int display_condition(t_mlx *mlx, int *x, int y, int *i)
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
	else if ((mlx->map)[y][*x] == 'N')
		*i = 5;
	else if ((mlx->map)[y][*x] == 'C')
	{
		display_coin(mlx, *x, y);
		(*x)++;
		return (0);
	}
	else
	{
		(*x)++;
		return (0);
	}
	return (1);
}

void display_row(t_mlx *mlx, int y)
{
	int x;
	int i;
	char *tmp;

	x = 0;
	while (x < mlx->size_x)
	{
		if (display_condition(mlx, &x, y, &i))
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[i], x * 64, y * 64);
			tmp = ft_itoa(mlx->moves);
			mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF, tmp);
			free(tmp);
			tmp = NULL;
			x++;
		}
	}
}

int display_map(void *param)
{
	int y;
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	display_ground(mlx);
	while (y < mlx->size_y)
	{
		display_row(mlx, y);
		y++;
	}
	return (0);
}
