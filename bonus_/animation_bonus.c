/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:45:25 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/26 15:22:39 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_imgs(t_mlx *mlx)
{
	int	i;

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
		mlx->coin_img[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->coin_frames[i], \
			&mlx->size_img, &mlx->size_img);
		if (mlx->coin_img[i] == NULL)
			error("Error\ncoin Error\n");
		i++;
	}
}

int	coin_animation(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		mlx->index_c++;
		while (x < mlx->size_x)
		{
			if (mlx->map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
					mlx->img[0], x * 64, y * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
					mlx->coin_img[(mlx->index_c % 140) / 20], x * 64, y * 64);
				if (mlx->index_c == 140)
					mlx->index_c = 0;
			}
			x++;
		}
		y++;
	}
	enemy_animation(mlx);
	return (0);
}

void	enemy_imgs(t_mlx *mlx)
{
	char	*frames[8];
	int		i;

	frames[0] = "textures/mob/mob0.xpm";
	frames[1] = "textures/mob/mob1.xpm";
	frames[2] = "textures/mob/mob2.xpm";
	frames[3] = "textures/mob/mob3.xpm";
	frames[4] = "textures/mob/mob4.xpm";
	frames[5] = "textures/mob/mob5.xpm";
	frames[6] = "textures/mob/mob6.xpm";
	frames[7] = "textures/mob/mob7.xpm";
	i = 0;
	while (i < 8)
	{
		mlx->mob_img[i] = mlx_xpm_file_to_image(mlx->mlx, \
			frames[i], &mlx->size_img, &mlx->size_img);
		if (mlx->mob_img[i] == NULL)
			error("Error\nmob Error\n");
		i++;
	}
}

void	enemy_move(t_mlx *mlx)
{
	if (mlx->index_n == 30)
	{
		if (mlx->x_n < mlx->size_x && mlx->y_n < mlx->size_y)
		{
			if (mlx->map[mlx->y_n + 1][mlx->x_n] == '1' \
				&& mlx->map[mlx->y_n - 1][mlx->x_n] == '1')
				return ;
			else
				move_n(mlx);
			display_map(mlx);
		}
	}
}

void	enemy_animation(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			if (mlx->map[y][x] == 'N')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
					mlx->img[0], x * 64, y * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
					mlx->mob_img[(mlx->index_n % 40) / 5], x * 64, y * 64);
				mlx->index_n++;
				enemy_move(mlx);
				if (mlx->index_n == 40)
					mlx->index_n = 0;
			}
			x++;
		}
		y++;
	}
}
