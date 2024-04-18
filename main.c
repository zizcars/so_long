/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:28 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/18 16:18:02 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(char *error_message)
{
	write(STDERR, error_message, ft_strlen(error_message));
	// system("leaks so_long");
	exit(1);
}


int main(int argc, char **argv)
{
	t_mlx mlx;

	mlx.size_img = 64;
	if (argc != 2)
		error("Enter a map <*.ber>");
	check_path(argv[1]);
	mlx.mlx = mlx_init();
	create_bas(argv[1], &map, &mlx, &coor);
	gra_map(&map, &mlx, &coor);
	// mlx_key_hook(mlx.win, )
	mlx_loop(mlx.mlx);
}