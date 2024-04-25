/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/25 14:28:04 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			mlx_put_image_to_window(mlx->mlx,
									mlx->win, mlx->img[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

// void	display_coin(t_mlx *mlx, int x, int y)
// {
// 	char	*tmp;

// 	mlx->index++;
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, \
// 		mlx->coin_img[(mlx->index % 70) / 10], x * 64, y * 64);
// 	tmp = ft_itoa(mlx->moves);
// 	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF, tmp);
// 	free(tmp);
// 	tmp = NULL;
// }

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
	// else if ((mlx->map)[y][*x] == 'N')
	// 	*i = 5;
	// else if ((mlx->map)[y][*x] == 'C')
	// {
	// 	display_coin(mlx, *x, y);
	// 	(*x)++;
	// 	return (0);
	// }
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
			mlx_put_image_to_window(mlx->mlx,mlx->win, mlx->img[i], x * 64, y * 64);
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

int coin_animation(t_mlx *mlx)
{
	int x, y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			if (mlx->map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], x * 64, y * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->coin_img[(mlx->index_c % 70) / 10], x * 64, y * 64);
				mlx->index_c++;
				if (mlx->index_c == 70)
					mlx->index_c = 0;
			}
			x++;
		}
		y++;
	}
	enemy_animation(mlx);
	return (0);
}

void enemy_imgs(t_mlx *mlx)
{
	char *frames[8];
	int i;

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
		mlx->mob_img[i] = mlx_xpm_file_to_image(mlx->mlx, frames[i],&mlx->size_img, &mlx->size_img);
		if (mlx->mob_img[i] == NULL)
			error("Error\nmob Error\n");
		i++;
	}
}
int enemy_animation(t_mlx *mlx)
{
	int x, y;

	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			if (mlx->map[y][x] == 'N')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], x * 64, y * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mob_img[(mlx->index_n % 40) / 5], x * 64, y * 64);
				mlx->index_n++;
				if (mlx->index_n == 40)
					mlx->index_n = 0;
			}
			x++;
		}
		y++;
	}
	return (0);
}