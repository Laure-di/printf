/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:13:11 by lauremass         #+#    #+#             */
/*   Updated: 2021/03/22 17:14:02 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_alpha(char c)
{
	if ((97 <= c && c <= 122) || (65 <= c && c <= 90))
		return (1);
	return (0);
}

int		is_digit(char c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			res = res * (-1);
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
