/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:30:56 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/16 16:24:31 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_char(char *str, int x)
{
	char *check;
	int i;
	int j;
	int len;

	check = "10PEC";
	i = 0;
	len = ft_strlen(str);
	if (len > 1 && ft_strchr(str, '\n'))
		str[len-- - 1] = '\0';
	if (len != x || str[len - 1] != '1' || str[0] != '1')
		error("error2\n");
	while (str && str[i])
	{
		j = 0;
		while (check[j])
		{
			if (check[j] == str[i])
				break;
			j++;
		}
		if (check[j] == '\0')
			error("error3\n");
		i++;
	}
}

void check_start_end(char *str)
{
	int i;

	i = 0;
	while (str && (str[i] != '\n' && str[i]))
	{
		if (str[i] != '1')
			error("error6\n");
		i++;
	}
}

void map_arr(char *file_name)
{
	int fd;
	char *str;
	int x = 0;
	int y = 0;
	char *tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error("error1\n");
	str = get_next_line(fd);
	check_start_end(str);
	x = ft_strlen(str) - 1;
	while (str)
	{
		check_char(str, x);
		tmp = str;
		str = get_next_line(fd);
		if ((str == NULL || str[0] == '\n'))
			check_start_end(tmp);
		free(tmp);
		y++;
	}
	if (x == y || x == -1)
		error("error5\n");
	ft_printf("x=%d, y=%d\n", x, y);
	close(fd);
}
