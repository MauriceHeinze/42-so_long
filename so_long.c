/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:08:49 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 16:42:34 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 4K (4,096 x 2,160) -> 2160 / 64 = 33,75
void	init_program(t_program *program)
{
	program->map = malloc(sizeof(char *) * 33);
	program->items_collected = 0;
	program->total_players = 0;
	program->total_collectable_items = 0;
}

int	add_line(t_program *program, int row, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		program->map[row] = ft_strdup(line);
		program->map_size_height++;
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	read_map(t_program *program, int fd)
{
	int	read;
	int	row;

	read = 1;
	row = 0;
	while (read)
	{
		read = add_line(&(*program), row, fd);
		row++;
	}
	program->map_size_width = ft_strlen_without_nl(program->map[0]);
	program->map_size_height = row;
	return (1);
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_program	program;

	if (argc < 2)
		return (error_message(-10));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_message(-11));
	if (!is_ber_file(argv[1]))
		return (error_message(-12));
	init_program(&program);
	read_map(&program, fd);
	if (!map_is_valid(&program))
		return (0);
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx,
			program.map_size_width * 64, (program.map_size_height - 1) * 64,
			"Para & Amcas: Haftbefehl Edition");
	setup_textures(&program);
	display_map(&program);
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop(program.mlx);
	return (0);
}
