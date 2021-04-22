/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:21:55 by lmasson           #+#    #+#             */
/*   Updated: 2021/04/22 13:33:12 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		is_width(char c, t_flags *flags)
{
	if (is_digit(c) && flags->dot == 0)
		flags->width = (flags->width * 10) + (c - '0');
}

void		is_precision(char c, t_flags *flags)
{
	if (is_digit(c) && flags->dot > 0 && flags->minus_precision == 0)
		flags->precision = (flags->precision * 10) + (c - '0');
}

void		initialize_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->stars_width = 0;
	flags->stars_precision = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->minus_precision = 0;
}

void		check_flags(char *format, int *i, t_flags *flags)
{
	initialize_flags(flags);
	while (format[*i])
	{
		if (format[*i] == '-' && flags->dot == 0)
			flags->minus = 1;
		if (format[*i] == '0' && !is_digit(format[*i - 1]) &&
				flags->minus == 0 && flags->dot == 0)
			flags->zero = 1;
		is_stars_width(format[*i], flags);
		is_stars_precision(format[*i], flags);
		if (format[*i] == '.')
			flags->dot = *i;
		if (is_specifier(format[*i], &flags->specifier))
		{
			flags->specifier = format[*i];
			(*i)++;
			return ;
		}
		is_minus_precision(format[*i], flags);
		is_width(format[*i], flags);
		is_precision(format[*i], flags);
		(*i)++;
	}
}

t_flags		define_all_flags(char *format, int *i, va_list pa)
{
	t_flags	flags;

	check_flags(format, i, &flags);
	if (flags.stars_precision == 1 || flags.stars_width == 1)
	{
		if (flags.stars_width == 1)
		{
			flags.width = va_arg(pa, int);
			if (flags.width < 0)
			{
				flags.width *= (-1);
				flags.minus = 1;
			}
		}
		if (flags.stars_precision == 1)
		{
			flags.precision = va_arg(pa, int);
			if (flags.precision < 0)
				flags.precision = -1;
		}
	}
	if (flags.minus == 1 && flags.zero == 1)
		flags.zero = 0;
	return (flags);
}
