/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:30:56 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/24 14:02:12 by Achakkaf         ###   ########.fr       */
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
		error("the map doesn't srounded by walls\n");
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
			error("undefined character\n");
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
			error("no walls in start and end\n");
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

void	map_checker(char *filename, t_mlx *mlx)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("can't open the file\n");
	map_reader(mlx, fd);
	close(fd);
	if (mlx->n_e != 1)
		error("The number of E in the map does not match\n");
	if (mlx->n_p != 1)
		error("The number of P in the map does not match\n");
	if (mlx->n_c < 1)
		error("The number of C in the map does not match\n");
	if (mlx->n_n > 1)
		error("The number of N in the map does not match\n");
	if (mlx->size_x == -1)
		error("error\n");
}
