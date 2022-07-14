/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:13:19 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 16:44:57 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_text(char *text_data, int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(text_data, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		text_data = ft_strjoin(text_data, buffer);
	}
	free(buffer);
	return (text_data);
}

char	*get_next_line(int fd)
{
	static char	*text_data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text_data = ft_read_text(text_data, fd);
	if (!text_data)
		return (NULL);
	line = ft_get_line(text_data);
	text_data = ft_new_text(text_data);
	return (line);
}
