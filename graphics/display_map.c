/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:08:49 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 12:01:16 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	setup_textures(t_program *program)
{
	program->player = ft_new_texture(&program->mlx, "./assets/player.xpm");
	program->wall = ft_new_texture(&program->mlx, "./assets/wall.xpm");
	program->collectable = ft_new_texture(&program->mlx,
			"./assets/collectable.xpm");
	program->exit = ft_new_texture(&program->mlx, "./assets/door.xpm");
	program->floor = ft_new_texture(&program->mlx, "./assets/floor.xpm");
}

void	display_image(t_program *program, int c, int x, int y)
{
	if (c == '0')
		display_floor(program, x, y);
	else if (c == '1')
		display_wall(program, x, y);
	else if (c == 'P')
		display_player(program, x, y);
	else if (c == 'E')
		display_exit(program, x, y);
	else if (c == 'C')
		display_collectable(program, x, y);
}

void	check_exit(t_program *program)
{
	if (program->exit_x != 0 && program->exit_y != 0)
	{
		if (program->map[program->exit_y][program->exit_x] != 'P')
			program->map[program->exit_y][program->exit_x] = 'E';
	}
}

void	display_map(t_program *program)
{
	int		counter_x;
	int		counter_y;
	char	**map;
	int		game_object;

	counter_x = 0;
	counter_y = 0;
	map = program->map;
	check_exit(program);
	while (counter_y < program->map_size_height - 1)
	{
		while (counter_x < program->map_size_width)
		{
			game_object = map[counter_y][counter_x];
			display_image(program, map[counter_y][counter_x], counter_x * 64,
				counter_y * 64);
			counter_x++;
		}
		counter_x = 0;
		counter_y++;
	}
}
