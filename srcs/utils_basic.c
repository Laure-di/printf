/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:13:11 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/21 13:04:24 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*initialize_str_zero(int size)
{
	char	*buff;
	int		j;

	j = 0;
	buff = malloc(sizeof(*buff) * size);
	if (!buff)
		return (NULL);
	while (j < ((int)(sizeof(*buff) * size) - 1))
	{
		buff[j] = '0';
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			is_alpha(char c)
{
	if ((97 <= c && c <= 122) || (65 <= c && c <= 90))
		return (1);
	return (0);
}

int			is_digit(char c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

void		ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}
