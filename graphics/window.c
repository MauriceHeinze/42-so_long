/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:08:49 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 17:07:43 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(void)
{
	exit(0);
	return (0);
}

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}
