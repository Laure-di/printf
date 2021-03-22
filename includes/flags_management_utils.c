/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_management_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:44:48 by lauremass         #+#    #+#             */
/*   Updated: 2021/03/22 17:10:48 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_minus_precision(char c, t_flags *flags)
{
	if (c == '-' && flags->dot > 0)
	{
		flags->minus_precision = 1;
		flags->precision = -1;
	}
}

void	is_minus(char c, t_flags *flags)
{
	if (c == '-' && flags->dot == 0)
		flags->minus = 1;
}

void	is_stars_width(char c, t_flags *flags)
{
	if (c == '*' && flags->dot == 0)
		flags->stars_width = 1;
}

void	is_stars_precision(char c, t_flags *flags)
{
	if (c == '*' && flags->dot > 0)
		flags->stars_precision = 1;
}
