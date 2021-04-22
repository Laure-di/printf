/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str_mng.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:03:26 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/22 12:52:14 by lauremass        ###   ########.fr       */
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

void	is_negative(char *dst, char *src, int *i, int *minus)
{
	dst[0] = src[0];
	*minus = *i;
	*i += 1;
}

char	*ft_strcpy_int(char *dst, char *src, t_flags flags)
{
	int		j;
	int		i;
	int		minus;
	int		len_src;

	i = 0;
	j = 0;
	len_src = ft_strlen(src);
	if (src[0] == '-')
		is_negative(dst, src, &i, &minus);
	while (j++ < (flags.precision - len_src))
		dst[i++] = '0';
	if (src[minus++] == '-')
		while (src[minus])
			dst[i++] = src[minus++];
	else
	{
		j = 0;
		while (src[j])
			dst[i++] = src[j++];
	}
	return (dst);
}

int		zero_fill(char *dst, char *src, int *len, int *count)
{
	int j;
	int minus;

	j = ft_strlen(src) - 1;
	minus = 0;
	while (0 <= j)
	{
		dst[*len] = src[j];
		j--;
		(*len)--;
		(*count)++;
		if (src[j] == '-')
		{
			*count += 1;
			minus = 1;
			break ;
		}
	}
	return (minus);
}

char	*ft_strcpyend_int(char *dst, char *src, int len, t_flags flags)
{
	int		j;
	int		count;
	int		minus;

	j = ft_strlen(src) - 1;
	count = 0;
	minus = 0;
	len--;
	minus = zero_fill(dst, src, &len, &count);
	while (count < flags.precision || (flags.zero == 1 && count < flags.width))
	{
		dst[len--] = '0';
		count++;
	}
	if (minus == 1)
		dst[len] = '-';
	return (dst);
}
