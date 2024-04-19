/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/19 16:15:57 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/// @brief display ground
/// @param mlx 
void create_base(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/env/ground2.xpm", &mlx->size_img, &mlx->size_img);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void display_map(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	create_base(mlx);
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			if ((mlx->map)[y][x] == '1')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/env/wall.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else if ((mlx->map)[y][x] == 'P')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/player/dir/down/down0.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else if ((mlx->map)[y][x] == 'C')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/collectible/coin0.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else if ((mlx->map)[y][x] == 'E')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/env/exit1.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else
			{
				x++;
				continue;
			}
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_key_hook(mlx->win, moves, (void *)mlx);
}
