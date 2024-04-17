/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:30:56 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/17 16:30:40 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_len(char *line)
{
	int len;

	len = 0;
	while (line && line[len] && line[len] != '\n')
		len++;
	return (len);
}

void count_char(t_count *count, char *line)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'C')
			count->n_C += 1;
		else if (line[i] == 'E')
			(count->n_E) += 1;
		else if (line[i] == 'P')
			(count->n_P) += 1;
		i++;
	}
}

void check_char(char *line, int max)
{
	char *check;
	int i;
	int j;
	int len;

	check = "10PEC";
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
				break;
			j++;
		}
		if (check[j] == '\0')
			error("undefined character\n");
		i++;
	}
}

void check_start_end(char *line)
{
	int i;

	i = 0;
	while (line && (line[i] != '\n' && line[i]))
	{
		if (line[i] != '1')
			error("no walls in start and end\n");
		i++;
	}
}

void set_default(t_coor *coor, t_count *count, int *fd, char *filename)
{
	coor->x = 0;
	coor->y = 0;
	coor->file = NULL;
	count->n_C = 0;
	count->n_P = 0;
	count->n_E = 0;
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		error("can't open the file\n");
}



t_coor map_checker(char *filename)
{
	int fd;
	char *line;
	char *tmp;
	t_coor coor;
	t_count count;

	set_default(&coor, &count, &fd, filename);
	line = get_next_line(fd);
	check_start_end(line);
	coor.x = ft_len(line);
	while (line && ft_len(line) == coor.x)
	{
		check_char(line, coor.x);
		count_char(&count, line);
		tmp = coor.file;
		coor.file = ft_strjoin(coor.file, line);
		free(tmp);
		tmp = line;
		line = get_next_line(fd);
		if ((line == NULL || line[0] == '\n'))
			check_start_end(tmp);

		free(tmp);
		coor.y++;
	}
	if (count.n_E != 1)
		error("The number of E in the map does not match\n");
	if (count.n_P != 1)
		error("The number of P in the map does not match\n");
	if (count.n_C < 1)
		error("The number of C in the map does not match\n");
	if (coor.x == -1)
		error("error\n");
	close(fd);
	return (coor);
}
