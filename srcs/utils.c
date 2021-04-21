/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:30:35 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/21 12:12:01 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strjoin(char *s1, char *s2)
{
	int		total_len;
	int		i;
	int		n;
	char	*s_final;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	s_final = malloc(sizeof(char) * total_len);
	if (!s_final)
		return (NULL);
	while (s1[n])
		s_final[i++] = (char)s1[n++];
	n = 0;
	while (s2[n])
	{
		s_final[i++] = (char)s2[n];
		n++;
	}
	s_final[i] = '\0';
	return (s_final);
}

char		*ft_strncpyend(char *dst, char *src, int len, int precision)
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

char		*ft_strncpy(char *dst, char *src, int n)
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

char		*ft_strcpyend(char *dst, char *src, int len)
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

char		*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i] && src)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
