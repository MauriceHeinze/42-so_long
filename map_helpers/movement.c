/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:08:49 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 12:41:01 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_program *program)
{
	char	**map;
	int		player_x;
	int		player_y;
	char	player_field;

	map = program->map;
	player_x = program->player_x;
	player_y = program->player_y;
	player_field = map[player_y - 1][player_x];
	if (player_field == 'E')
	{
		program->exit_x = player_x;
		program->exit_y = player_y - 1;
		if (program->items_collected == program->total_collectable_items)
			display_total_moves(&(*program));
	}
	if (player_field != '1')
	{
		move_on_map(program, 1, player_x, player_y);
		display_current_moves(&(*program));
	}
}

void	move_down(t_program *program)
{
	int		player_x;
	int		player_y;
	char	player_field;

	player_x = program->player_x;
	player_y = program->player_y;
	player_field = program->map[player_y + 1][player_x];
	if (player_field == 'E')
	{
		program->exit_x = player_x;
		program->exit_y = player_y + 1;
		if (program->items_collected == program->total_collectable_items)
			display_total_moves(&(*program));
	}
	if (player_field != '1')
	{
		move_on_map(program, 2, player_x, player_y);
		display_current_moves(&(*program));
	}
}

void	move_left(t_program *program)
{
	char	**map;
	int		player_x;
	int		player_y;
	char	player_field;

	map = program->map;
	player_x = program->player_x;
	player_y = program->player_y;
	player_field = map[player_y][player_x - 1];
	if (player_field == 'E')
	{
		program->exit_x = player_x - 1;
		program->exit_y = player_y;
		if (program->items_collected == program->total_collectable_items)
			display_total_moves(&(*program));
	}
	if (player_field != '1')
	{
		move_on_map(program, 3, player_x, player_y);
		display_current_moves(&(*program));
	}
}

void	move_right(t_program *program)
{
	char	**map;
	int		player_x;
	int		player_y;
	char	player_field;

	map = program->map;
	player_x = program->player_x;
	player_y = program->player_y;
	player_field = map[player_y][player_x + 1];
	if (player_field == 'E')
	{
		program->exit_x = player_x + 1;
		program->exit_y = player_y;
		if (program->items_collected == program->total_collectable_items)
			display_total_moves(&(*program));
	}
	if (player_field != '1')
	{
		move_on_map(program, 4, player_x, player_y);
		display_current_moves(&(*program));
	}
}
