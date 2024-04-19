/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:28 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/19 12:58:02 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief convert from string to 2D array
/// @param mlx 
void	map_arr(t_mlx *mlx)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	mlx->map = ft_malloc(sizeof(char *) * mlx->size_y);
	mlx->cpy = ft_malloc(sizeof(char *) * mlx->size_y);
	while (y < mlx->size_y)
	{
		x = 0;
		mlx->map[y] = ft_malloc(sizeof(char) * (mlx->size_x + 1));
		mlx->cpy[y] = ft_malloc(sizeof(char) * (mlx->size_x + 1));
		while(x < mlx->size_x)
		{
			mlx->map[y][x] = mlx->file[i];
			mlx->cpy[y][x] = mlx->file[i];
			x++;
			i++;
		}
		mlx->map[y][x] = '\0';
		mlx->cpy[y][x] = '\0';
		y++;
	}
}


/// @brief print error  in stderr and exit with 1
/// @param error_message 
void error(char *error_message)
{
	write(STDERR, error_message, ft_strlen(error_message));
	exit(1);
}

int main(int argc, char **argv)
{
	t_mlx mlx;

	mlx.size_img = 64;
	if (argc != 2)
		error("Enter a map <*.ber>");
	map_checker(argv[1], &mlx);
	map_arr(&mlx);
	check_path(&mlx);
	mlx.mlx = mlx_init();
	gra_map(&mlx);
	mlx_loop(mlx.mlx);
}
