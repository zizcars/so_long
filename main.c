/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:28 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/19 16:40:39 by Achakkaf         ###   ########.fr       */
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

void set_default(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = NULL;
	mlx->cpy = NULL;
	mlx->file = NULL;
	mlx->img = NULL;
	mlx->map = NULL;
	mlx->n_C = 0;
	mlx->n_E = 0;
	mlx->n_P = 0;
	mlx->size_win_x = 0;
	mlx->size_win_y = 0;
	mlx->size_x = 0;
	mlx->size_y = 0;
	mlx->x_E = 0;
	mlx->y_E = 0;
}

int main(int argc, char **argv)
{
	t_mlx mlx;

	mlx.size_img = 64;
	if (argc != 2)
		error("Enter a map <*.ber>");
	set_default(&mlx);
	map_checker(argv[1], &mlx);
	map_arr(&mlx);
	check_path(&mlx);
	find_P(&mlx, &(mlx.x_E), &(mlx.y_E), 'E');
	mlx.size_win_x = mlx.size_x * 64;
	mlx.size_win_y = mlx.size_y * 64;
	mlx.win = mlx_new_window(mlx.mlx, mlx.size_win_x, mlx.size_win_y, "so_long");
	display_map(&mlx);
	
	mlx_loop(mlx.mlx);
}
