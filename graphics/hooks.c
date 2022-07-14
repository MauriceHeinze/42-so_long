/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:08:49 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 17:07:37 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_input(int key, t_program *program)
{
	mlx_clear_window(program->mlx, program->window.reference);
	if (key == 2)
		move_right(&(*program));
	else if (key == 0)
		move_left(&(*program));
	else if (key == 1)
		move_down(&(*program));
	else if (key == 13)
		move_up(&(*program));
	else if (key == 53)
		exit(0);
	display_map(&(*program));
	return (0);
}
