/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:30:56 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/17 11:13:41 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_char(t_count *count, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			count->n_C += 1;
		else if (line[i] == 'E')
		{
			(count->n_E) += 1;
			if (count->n_E != 1)
				error("problem in E\n");
		}
		else if (line[i] == 'P')
		{
			(count->n_P) += 1;
			if (count->n_P != 1)
				error("problem in P\n");
		}
		i++;
	}
}

void check_char(char *line, int x)
{
	char *check;
	int i;
	int j;
	int len;

	check = "10PEC";
	i = 0;
	len = ft_strlen(line);
	if (len > 1 && ft_strchr(line, '\n'))
		line[--len] = '\0';
	if (len != x || line[len - 1] != '1' || line[0] != '1')
		error("error2\n");
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
			error("error3\n");
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
			error("error6\n");
		i++;
	}
}

t_coor map_arr(char *file_name)
{
	int fd;
	char *line;
	char *tmp;
	t_coor coor;
	t_count count;

	coor.x = 0;
	coor.y = 0;
	count.n_C = 0;
	count.n_P = 0;
	count.n_E = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error("error1\n");
	line = get_next_line(fd);
	check_start_end(line);
	coor.x = ft_strlen(line) - 1;
	while (line)
	{
		check_char(line, coor.x);
		count_char(&count, line);
		tmp = line;
		line = get_next_line(fd);
		if ((line == NULL || line[0] == '\n'))
			check_start_end(tmp);
		free(tmp);
		coor.y++;
	}
	if (coor.x == coor.y || coor.x == -1 || count.n_C < 1)
		error("error5\n");
	close(fd);
	return (coor);
}
