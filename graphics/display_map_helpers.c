/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:08:49 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 12:01:12 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_player(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->player.reference, x, y);
}

void	display_wall(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->wall.reference, x, y);
}

void	display_exit(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->exit.reference, x, y);
}

void	display_collectable(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->collectable.reference, x, y);
}

void	display_floor(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->floor.reference, x, y);
}
