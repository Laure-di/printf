/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:34:16 by lmasson           #+#    #+#             */
/*   Updated: 2021/04/21 12:11:34 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c, char *specifier)
{
	if (c == 99 || c == 105 || c == 115 || c == 112 || c == 100
		|| c == 117 || c == 120 || c == 88)
	{
		*specifier = c;
		return (1);
	}
	if (c == '%')
	{
		*specifier = '%';
		return (1);
	}
	return (0);
}

int		check_valid_specifier(char *format, int i, char *specifier)
{
	i++;
	while (format[i])
	{
		if (is_alpha(format[i]) || format[i] == '%')
		{
			if (is_specifier(format[i], specifier))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}
