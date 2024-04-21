/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:42:13 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/21 15:02:11 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_coin(t_mlx *mlx)
{
	char *coin_path[7];
	int i;

	i = 0;
	coin_path[0] = "textures/collectible/coin0.xpm";
	coin_path[1] = "textures/collectible/coin1.xpm";
	coin_path[2] = "textures/collectible/coin2.xpm";
	coin_path[3] = "textures/collectible/coin3.xpm";
	coin_path[4] = "textures/collectible/coin4.xpm";
	coin_path[5] = "textures/collectible/coin5.xpm";
	coin_path[6] = "textures/collectible/coin6.xpm";
	while (i < 6)
	{
		mlx->img_coin[i] = mlx_xpm_file_to_image(mlx->mlx, coin_path[i], &mlx->size_img, &mlx->size_img);
		if (mlx->img_coin[i] == NULL)
			error("invalid image\n");
		i++;
	}
}

void animation(t_mlx *mlx, int x, int y)
{
	mlx->coin_i++;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_coin[(mlx->coin_i % 70) / 10], x, y);
}