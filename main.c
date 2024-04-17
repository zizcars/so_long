/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:56:28 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/17 16:11:37 by Achakkaf         ###   ########.fr       */
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
	if (argc != 2)
		error("Enter a map <*.ber>");

	check_path(argv[1]);
	// system("leaks so_long");
	return (0);
}