/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:39:32 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/22 12:56:04 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*s1_copy;

	len = ft_strlen(s1) + 1;
	i = 0;
	s1_copy = malloc((sizeof(char) * len));
	if (!s1_copy)
		return (NULL);
	while (s1[i])
	{
		s1_copy[i] = s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}

void	write_space(int j, int *count, int width)
{
	while (j < width)
	{
		write(1, " ", 1);
		*count += 1;
		j++;
	}
}
