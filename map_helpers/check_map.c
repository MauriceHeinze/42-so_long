/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:33:01 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/14 10:17:23 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	final_check(t_program *program, char *row)
{
	if (!check_wall(row))
		return (0);
	if (!program->total_players)
		return (error_message(-6));
	if (program->total_players > 1)
		return (error_message(-7));
	if (!program->total_exits)
		return (error_message(-8));
	if (!program->total_collectable_items)
		return (error_message(-9));
	program->map_size_width = ft_strlen_without_nl(row);
	return (1);
}

int	check_wall(char *row)
{
	if (ft_strchr(row, '0') || ft_strchr(row, 'P'))
		return (error_message(-3));
	if (ft_strchr(row, 'C') || ft_strchr(row, 'E'))
		return (error_message(-3));
	return (1);
}

int	forbidden_char(const char *row)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(row) - 1)
	{
		if ((row[i] != '0') && (row[i] != '1') && (row[i] != 'P')
			&& (row[i] != 'E') && (row[i] != 'C'))
			return (1);
		else
			i++;
	}
	return (0);
}

int	check_character(t_program *program, int row_nbr, int row_length, char *row)
{
	if (program->total_players > 1)
		return (error_message(-1));
	if (ft_strlen_without_nl(row) != row_length)
		return (error_message(-2));
	if (row[0] != '1' || (row[row_length - 1] != '1'))
		return (error_message(-3));
	if (forbidden_char(row))
		return (error_message(-12));
	if (ft_strchr(row, 'E'))
		program->total_exits++;
	if (ft_strchr(row, 'P'))
	{
		set_player_pos(row, row_nbr, &(*program));
		program->total_players++;
	}
	if (ft_strchr(row, 'C'))
		program->total_collectable_items += str_found(row, 'C');
	return (1);
}

int	map_is_valid(t_program *program)
{
	char	*row;
	int		row_nbr;
	int		collectible;
	int		row_length;

	row_nbr = 0;
	row = program->map[row_nbr];
	row_length = program->map_size_width;
	collectible = 0;
	if (!check_wall(row))
		return (0);
	row_nbr++;
	while (row_nbr < (program->map_size_height - 2) && row)
	{
		if (row_nbr > 33 || row_length > 66)
			return (error_message(-4));
		row = program->map[row_nbr];
		if (!check_character(program, row_nbr, row_length, row))
			return (0);
		row = program->map[++row_nbr];
	}
	if (!final_check(program, row))
		return (0);
	return (1);
}
