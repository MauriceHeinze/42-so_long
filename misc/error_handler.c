/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:23 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 20:18:02 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_ber_file(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
	{
		if (filename[i] == '.')
		{
			if ((filename[i + 1] == 'b') && (filename[i + 2] == 'e')
				&& (filename[i + 3] == 'r') && (filename[i + 4] == '\0'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	error_message(int error_code)
{
	if (error_code == -1)
		write(1, "Too many players!\n", 18);
	else if (error_code == -2)
		write(1, "Map is not rectangular!\n", 24);
	else if (error_code == -3)
		write(1, "Map is not surrounded by walls!\n", 32);
	else if (error_code == -4)
		write(1, "Map is too big!\n", 16);
	else if (error_code == -5)
		write(1, "Map does not have all required items!\n", 38);
	else if (error_code == -6)
		write(1, "Map has no player!\n", 19);
	else if (error_code == -7)
		write(1, "Map has too many players\n", 25);
	else if (error_code == -8)
		write(1, "Map has no exits!\n", 18);
	else if (error_code == -9)
		write(1, "Map has no items to collect!\n", 29);
	else if (error_code == -10)
		write(1, "No map!\n", 7);
	else if (error_code == -11)
		write(1, "Invalid path!\n", 14);
	else if (error_code == -12)
		write(1, "Invalid input!\n", 15);
	return (0);
}
