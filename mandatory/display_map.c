/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/24 12:18:54 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_img(t_mlx *mlx)
{
	char	*frames[5];
	int		i;

	i = 0;
	frames[0] = "textures/ground.xpm";
	frames[1] = "textures/wall.xpm";
	frames[2] = "textures/player.xpm";
	frames[3] = "textures/coin/coin0.xpm";
	frames[4] = "textures/exit1.xpm";
	while (i < 5)
	{
		mlx->img[i] = mlx_xpm_file_to_image(mlx->mlx, \
			frames[i], &mlx->size_img, &mlx->size_img);
		if (mlx->img[i] == NULL)
			error("invalid image\n");
		i++;
	}
}

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

void	display_row(t_mlx *mlx, int y)
{
	int	x;
	int	i;

	x = 0;
	while (x < mlx->size_x)
	{
		if ((mlx->map)[y][x] == '1')
			i = 1;
		else if ((mlx->map)[y][x] == 'P')
			i = 2;
		else if ((mlx->map)[y][x] == 'C')
			i = 3;
		else if ((mlx->map)[y][x] == 'E')
			i = 4;
		else
		{
			x++;
			continue ;
		}
		mlx_put_image_to_window(mlx->mlx, \
			mlx->win, mlx->img[i], x * 64, y * 64);
		x++;
	}
}

void	display_map(t_mlx *mlx)
{
	int	y;

	y = 0;
	display_ground(mlx);
	while (y < mlx->size_y)
	{
		display_row(mlx, y);
		y++;
	}
}
