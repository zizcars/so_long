/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:42:13 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/24 18:22:18 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_len(char *line)
{
	int	len;

	len = 0;
	while (line && line[len] && line[len] != '\n')
		len++;
	return (len);
}

void	count_char(t_mlx *mlx, char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'C')
			mlx->n_c += 1;
		else if (line[i] == 'E')
			(mlx->n_e) += 1;
		else if (line[i] == 'P')
			(mlx->n_p) += 1;
		else if (line[i] == 'N')
			(mlx->n_n) += 1;
		i++;
	}
}

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

void	mlx_img(t_mlx *mlx)
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
		mlx->img[i] = mlx_xpm_file_to_image(mlx->mlx, frames[i], \
			&mlx->size_img, &mlx->size_img);
		if (mlx->img[i] == NULL)
			error("Error\nInvalid image\n");
		i++;
	}
}
