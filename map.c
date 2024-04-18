/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/18 16:13:10 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_bas(char *filename, t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	*map = map_arr(filename, coor);
	mlx->x_win = coor->x * 64;
	mlx->y_win = coor->y * 64;
	mlx->win = mlx_new_window(mlx->mlx, mlx->x_win, mlx->y_win, "so_long");
	while (y < coor->y)
	{
		x = 0;
		while (x < coor->x)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/env/ground2.xpm", &mlx->size_img, &mlx->size_img);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void gra_map(t_map_cpy *map, t_mlx *mlx, t_coor *coor)
{
	int x;
	int y;

	y = 0;
	while (y < coor->y)
	{
		x = 0;
		while (x < coor->x)
		{
			if ((map->map)[y][x] == '1')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/env/wall.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else if ((map->map)[y][x] == 'P')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/player/dir/down/down0.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else if ((map->map)[y][x] == 'C')
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/collectible/coin0.xpm", &mlx->size_img, &mlx->size_img);
				if (mlx->img == NULL)
					error("invalid image\n");
			}
			else if ((map->map)[y][x] == 'E')
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
}
