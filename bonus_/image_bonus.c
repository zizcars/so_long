/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:42:13 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/25 16:46:04 by Achakkaf         ###   ########.fr       */
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

void	mlx_img(t_mlx *mlx)
{
	char	*frames[5];
	int		i;

	i = 0;
	frames[0] = "textures/ground.xpm";
	frames[1] = "textures/wall.xpm";
	frames[2] = "textures/player.xpm";
	frames[3] = "textures/exit0.xpm";
	frames[4] = "textures/exit1.xpm";
	while (i < 5)
	{
		mlx->img[i] = mlx_xpm_file_to_image(mlx->mlx, frames[i], \
			&mlx->size_img, &mlx->size_img);
		if (mlx->img[i] == NULL)
			error("Error\nInvalid image\n");
		i++;
	}
}

int	moves(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	find_p(mlx, &mlx->x_p, &mlx->y_p, 'P');
	if (keycode == A || keycode == L_ARROW)
		move_(mlx, mlx->x_p - 1, mlx->y_p);
	else if (keycode == S || keycode == D_ARROW)
		move_(mlx, mlx->x_p, mlx->y_p + 1);
	else if (keycode == D || keycode == R_ARROW)
		move_(mlx, mlx->x_p + 1, mlx->y_p);
	else if (keycode == W || keycode == U_ARROW)
		move_(mlx, mlx->x_p, mlx->y_p - 1);
	else if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}
