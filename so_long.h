/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:05:26 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/14 10:17:07 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./GNL/get_next_line.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <fcntl.h>

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

/* all info needed to run the game itself */
typedef struct s_program
{
	void			*mlx;
	t_window		window;
	t_image			player;
	t_image			floor;
	t_image			collectable;
	t_image			wall;
	t_image			exit;
	t_vector		player_position;
	char			**map;
	int				map_size_width;
	int				map_size_height;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				total_exits;
	int				total_collectable_items;
	int				items_collected;
	int				total_players;
	int				total_moves;
}					t_program;

t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image		ft_new_texture(void *mlx, char *path);
int			ft_input(int key, t_program *program);

void	setup_textures(t_program *program);
void	display_wall(t_program *program, int x, int y);
void	display_player(t_program *program, int x, int y);
void	display_exit(t_program *program, int x, int y);
void	display_collectable(t_program *program, int x, int y);
void	display_floor(t_program *program, int x, int y);
void	display_map(t_program *program);
void	display_current_moves(t_program *program);
void	display_total_moves(t_program *program);

void	ft_putnbr(int n);
int		ft_strlen_without_nl(const char *str);
int		str_found(const char *s, int c);

void	print_map(t_program *program);

void	move_up(t_program *program);
void	move_left(t_program *program);
void	move_right(t_program *program);
void	move_down(t_program *program);

void	move_up_on_map(t_program *program, int player_x, int player_y);
void	move_down_on_map(t_program *program, int player_x, int player_y);
void	move_left_on_map(t_program *program, int player_x, int player_y);
void	move_right_on_map(t_program *program, int player_x, int player_y);
void	move_on_map(t_program *program, int direction, int player_x,
		int player_y);

int	error_message(int error_code);
int	is_ber_file(char *filename);
int	map_is_valid(t_program *program);
int	check_character(t_program *program, int row_nbr, int row_length, char *row);
int	check_wall(char *row);
int	final_check(t_program *program, char *row);
void	set_player_pos(const char *row, int row_nbr, t_program *program);

char	*ft_strdup(const char *s1);

#endif
