/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:34:16 by lmasson           #+#    #+#             */
/*   Updated: 2021/03/10 18:04:34 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c, char *specifier)
{
	if (c == 99 || c == 115 || c == 112 || c == 100
		|| c == 117 || c == 120 || c == 88)
	{
		*specifier = c;
		return (1);
	}
	return (0);
}

int		check_valid_specifier(char *format, int i, char *specifier)
{
	while (format[i])
	{
		if (is_alpha(format[i]))
		{
			if (is_specifier(format[i], specifier))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}
