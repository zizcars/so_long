/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:28 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/16 14:17:16 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(char *error_message)
{
	write(STDERR, error_message, ft_strlen(error_message));
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		error("Enter a map <*.ber>");
	map_arr(argv[1]);
}