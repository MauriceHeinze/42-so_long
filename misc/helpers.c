/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:56:41 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 16:42:19 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int n)
{
	int	c;

	if (n == -2147483648)
		write(1, "-2147483648\n", 12);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	str_found(const char *s, int c)
{
	int	i;
	int	times_found;

	i = 0;
	times_found = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			times_found++;
		i++;
	}
	return (times_found);
}

int	ft_strlen_without_nl(const char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0' && str[c] != '\n')
		c++;
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		str_len;

	str_len = ft_strlen(s1) + 1;
	dst = malloc(sizeof(char) * str_len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, str_len);
	return (dst);
}
