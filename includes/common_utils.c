/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:03:26 by lauremass         #+#    #+#             */
/*   Updated: 2021/03/22 17:06:13 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*initialize_str(int size)
{
	char	*buff;
	int		j;

	j = 0;
	buff = malloc(sizeof(*buff) * size);
	if (!buff)
		return (NULL);
	while (j < ((int)(sizeof(*buff) * size) - 1))
	{
		buff[j] = ' ';
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strcpyend(char *dst, char *src, int len)
{
	int		j;

	j = ft_strlen(src);
	len--;
	j--;
	while (0 <= j)
	{
		dst[len] = src[j];
		j--;
		len--;
	}
	return (dst);
}

char	*ft_strncpyend(char *dst, char *src, int len, int precision)
{
	len--;
	precision--;
	while (0 <= precision)
	{
		dst[len] = src[precision];
		precision--;
		len--;
	}
	return (dst);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int		j;

	j = 0;
	while (src[j] && src && j < n)
	{
		dst[j] = src[j];
		j++;
	}
	return (dst);
}
