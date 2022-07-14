/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_map_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:33:06 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 12:40:56 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up_on_map(t_program *program, int player_x, int player_y)
{
	program->map[player_y - 1][player_x] = 'P';
	program->player_y = player_y - 1;
}

void	move_down_on_map(t_program *program, int player_x, int player_y)
{
	program->map[player_y + 1][player_x] = 'P';
	program->player_y = player_y + 1;
}

void	move_left_on_map(t_program *program, int player_x, int player_y)
{
	program->map[player_y][player_x - 1] = 'P';
	program->player_x = player_x - 1;
}

void	move_right_on_map(t_program *program, int player_x, int player_y)
{
	program->map[player_y][player_x + 1] = 'P';
	program->player_x = player_x + 1;
}
