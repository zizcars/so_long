/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:12 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:45 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_img(t_mlx *mlx)
{
	mlx->img[0] = mlx_xpm_file_to_image(mlx->mlx, "textures/env/ground2.xpm", &mlx->size_img, &mlx->size_img);
	if (mlx->img[0] == NULL)
		error("invalid image <textures/env/ground2.xpm>\n");
	mlx->img[1] = mlx_xpm_file_to_image(mlx->mlx, "textures/env/wall.xpm", &mlx->size_img, &mlx->size_img);
	if (mlx->img[1] == NULL)
		error("invalid image <textures/env/wall.xpm>\n");
	mlx->img[2] = mlx_xpm_file_to_image(mlx->mlx, "textures/player/dir/down/down0.xpm", &mlx->size_img, &mlx->size_img);
	if (mlx->img[2] == NULL)
		error("invalid image <textures/player/dir/down/down0.xpm>\n");
	mlx->img[3] = mlx_xpm_file_to_image(mlx->mlx, "textures/collectible/coin0.xpm", &mlx->size_img, &mlx->size_img);
	if (mlx->img[3] == NULL)
		error("invalid image <textures/collectible/coin0.xpm>\n");
	mlx->img[4] = mlx_xpm_file_to_image(mlx->mlx, "textures/env/exit1.xpm", &mlx->size_img, &mlx->size_img);
	if (mlx->img[4] == NULL)
		error("invalid image textures/env/exit1.xpm\n");
	mlx->img[5] = mlx_xpm_file_to_image(mlx->mlx, "textures/mob/mob0.xpm", &mlx->size_img, &mlx->size_img);
	if (mlx->img[5] == NULL)
		error("invalid image textures/mob/mob0.xpm\n");
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
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	display_row(t_mlx *mlx, int y)
{
	int	x;
	int	i;
	char *tmp;

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
		else if ((mlx->map)[y][x] == 'N')
			i = 5;
		else
		{
			x++;
			continue ;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[i], x * 64, y * 64);
		tmp = ft_itoa(mlx->moves);
		mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF, tmp);
		free(tmp);
		tmp = NULL;
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
