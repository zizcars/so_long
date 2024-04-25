/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:28 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/25 14:13:56 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void create_map(t_mlx *mlx)
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
		while (x < mlx->size_x)
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
	mlx->map = NULL;
	mlx->n_c = 0;
	mlx->n_e = 0;
	mlx->n_p = 0;
	mlx->n_n = 0;
	mlx->size_win_x = 0;
	mlx->size_win_y = 0;
	mlx->size_x = 0;
	mlx->size_y = 0;
	mlx->x_e = 0;
	mlx->y_e = 0;
	mlx->moves = 0;
	mlx->index_c = 0;
	mlx->index_n = 0;
	mlx->up_down = 1;
	mlx->in_c = 0;
	mlx->x_c = 0;
	mlx->y_c = 0;
}

int mouse(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx mlx;

	mlx.size_img = 64;
	if (argc != 2)
		error("Error\nEnter a map <*.ber>");
	set_default(&mlx);
	map_checker(argv[1], &mlx);
	create_map(&mlx);
	check_path(&mlx);
	find_p(&mlx, &(mlx.x_e), &(mlx.y_e), 'E');
	mlx.size_win_x = mlx.size_x * 64;
	mlx.size_win_y = mlx.size_y * 64;
	mlx.win = mlx_new_window(mlx.mlx,
							 mlx.size_win_x, mlx.size_win_y, "so_long");
	mlx_img(&mlx);
	coin_imgs(&mlx);
	find_p(&mlx, &mlx.x_n, &mlx.y_n, 'N');
	enemy_imgs(&mlx);
	display_map(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, moves, (void *)&mlx);
	mlx_hook(mlx.win, 17, 0, mouse, (void *)&mlx);
	mlx_loop_hook(mlx.mlx, coin_animation, (void *)&mlx);
	// mlx_loop_hook(mlx.mlx, enemy_animation, (void *)&mlx);
	mlx_loop(mlx.mlx);
}
