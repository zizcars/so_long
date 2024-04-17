/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:54:44 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/17 15:51:24 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void *ft_malloc(size_t size)
{
    void *p;

	p = malloc(size);
    if (!p)
        error("out of memory error");
    return (p);
}

t_map_cpy map_arr(char *filename, t_coor *map_size)
{
	t_map_cpy map;
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	*map_size = map_checker(filename);
	// ft_printf("Ssjsdf");
	map.map = ft_malloc(sizeof(char *) * map_size->y);
	map.cpy = ft_malloc(sizeof(char *) * map_size->y);
	while (y < map_size->y)
	{
		x = 0;
		map.map[y] = ft_malloc(sizeof(char) * (map_size->x + 1));
		map.cpy[y] = ft_malloc(sizeof(char) * (map_size->x + 1));
		while(x < map_size->x)
		{
			map.map[y][x] = map_size->file[i];
			map.cpy[y][x] = map_size->file[i];
			x++;
			i++;
		}
		map.map[y][x] = '\0';
		map.cpy[y][x] = '\0';
		y++;
	}
	return (map);
}

void find_char(char **map, t_coor map_size, char c, t_coor *place_c)
{
	place_c->file = NULL;
	place_c->y = 0;
	while (place_c->y < map_size.y)
	{	
		place_c->x = 0;
		while(place_c->x < map_size.x)
		{
			if (map[place_c->y][place_c->x] == c)
				return;
			place_c->x++;
		}
		place_c->y++;
	}
}

void change_one(char ***cpy, int x, int y, t_coor map_size)
{
	if ((*cpy)[y][x] == '1' || ( 0 > x || x > map_size.x) || (map_size.y < y || y < 0) )
		return;
	else
		(*cpy)[y][x] = '1';
	change_one(cpy, x + 1, y, map_size);
	change_one(cpy, x - 1, y, map_size);
	change_one(cpy, x, y + 1, map_size);
	change_one(cpy, x, y - 1, map_size);
}

void check_map(char **cpy, t_coor map_size)
{
	int x;
	int y;

	y = 0;
	while (y < map_size.y)
	{
		x = 0;
		while (x < map_size.x)
		{
			if (cpy[y][x] == 'P' || cpy[y][x] == 'C' || cpy[y][x] == 'E')
				error("No path found\n");
			x++;
		}
		y++;
	}
}

void check_path(char *filename)
{
	t_map_cpy map;
	t_coor place_P;
	t_coor map_size;

	map = map_arr(filename, &map_size);
	// ft_printf("map check\n");
	find_char(map.cpy, map_size, 'P', &place_P);
	// ft_printf("Place_P:(%d,%d)\n", place_P.x, place_P.y);
	change_one(&map.cpy, place_P.x, place_P.y, map_size);
	check_map(map.cpy, map_size);
}
