/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:30:56 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/26 15:12:40 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_char(char *line, int max)
{
	char	*check;
	int		i;
	int		j;
	int		len;

	check = "10PECN";
	i = 0;
	len = ft_len(line);
	if (len > 1 && ft_strchr(line, '\n'))
		line[len] = '\0';
	if (len != max || line[len - 1] != '1' || line[0] != '1')
		error("Error\nthe map doesn't srounded by walls\n");
	while (line && line[i])
	{
		j = 0;
		while (check[j])
		{
			if (check[j] == line[i])
				break ;
			j++;
		}
		if (check[j] == '\0')
			error("Error\nundefined character\n");
		i++;
	}
}

void	check_start_end(char *line)
{
	int	i;

	i = 0;
	while (line && (line[i] != '\n' && line[i]))
	{
		if (line[i] != '1')
			error("Error\nNo walls in start and end\n");
		i++;
	}
}

void	map_reader(t_mlx *mlx, int fd)
{
	char	*tmp;
	char	*line;

	line = get_next_line(fd);
	check_start_end(line);
	mlx->size_x = ft_len(line);
	while (line)
	{
		check_char(line, mlx->size_x);
		count_char(mlx, line);
		tmp = mlx->file;
		mlx->file = ft_strjoin(mlx->file, line);
		free(tmp);
		tmp = line;
		line = get_next_line(fd);
		if (line == NULL)
			check_start_end(tmp);
		free(tmp);
		mlx->size_y++;
	}
}

void	check_filename(char *filename)
{
	char	*ber;
	int		i;
	int		len;

	ber = ".ber";
	len = ft_strlen(filename);
	i = len - 4;
	while (filename[i])
	{
		if (filename[i] != *ber)
			error("Error\nfilename doesn't end with .ber\n");
		i++;
		ber++;
	}
}

void	map_checker(char *filename, t_mlx *mlx)
{
	int		fd;

	check_filename(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Error\ncan't open the file\n");
	map_reader(mlx, fd);
	close(fd);
	if (mlx->n_e != 1)
		error("Error\nmore/less than one E\n");
	if (mlx->n_p != 1)
		error("Error\nmore/less than one P\n");
	if (mlx->n_c < 1)
		error("Error\nless than one C\n");
	if (mlx->n_n > 1)
		error("Error\nmore than one N\n");
	if (mlx->size_x == -1)
		error("Error\n");
}
