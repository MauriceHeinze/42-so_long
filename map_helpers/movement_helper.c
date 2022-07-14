/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:04:58 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/14 10:17:29 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_pos(const char *row, int row_nbr, t_program *program)
{
	int	i;

	i = 0;
	while (row[i] != 'P' && row[i] != '\0')
		i++;
	if (row[i] == 'P')
	{
		program->player_x = i;
		program->player_y = row_nbr;
	}
}

void	display_current_moves(t_program *program)
{
	write(1, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 20);
	write(1, "MOVES: ", 6);
	ft_putnbr(program->total_moves);
}

void	display_total_moves(t_program *program)
{
	program->total_moves++;
	write(1, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 20);
	write(1, "Congrats! You needed ", 22);
	ft_putnbr(program->total_moves);
	write(1, " Moves! 🥳", 12);
	exit(0);
}

// 1 up, 2 down, 3 left, 4 right
void	collect_item(t_program *program,
				int direction, int player_x, int player_y)
{
	program->map[player_y][player_x] = '0';
	if ((direction == 1) && (program->map[player_y - 1][player_x] == 'C'))
			program->items_collected++;
	else if ((direction == 2) && (program->map[player_y + 1][player_x] == 'C'))
			program->items_collected++;
	else if ((direction == 3) && (program->map[player_y][player_x - 1] == 'C'))
			program->items_collected++;
	else if ((direction == 4) && (program->map[player_y][player_x + 1] == 'C'))
			program->items_collected++;
}

// 1 up, 2 down, 3 left, 4 right
void	move_on_map(t_program *program,
				int direction, int player_x, int player_y)
{
	program->map[player_y][player_x] = '0';
	program->total_moves++;
	collect_item(program, direction, player_x, player_y);
	if (direction == 1)
		move_up_on_map(program, player_x, player_y);
	else if (direction == 2)
		move_down_on_map(program, player_x, player_y);
	else if (direction == 3)
		move_left_on_map(program, player_x, player_y);
	else if (direction == 4)
		move_right_on_map(program, player_x, player_y);
}
