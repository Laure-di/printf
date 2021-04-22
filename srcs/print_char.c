/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:34:59 by lmasson           #+#    #+#             */
/*   Updated: 2021/04/22 12:57:51 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_count(char c, int *j, int *count)
{
	write(1, &c, 1);
	*j += 1;
	*count += 1;
}

void		print_nullable_char(t_flags flags, char c, int *count)
{
	int j;

	j = 0;
	if (c == 0)
	{
		if (flags.minus == 1 && flags.width >= 0)
		{
			ft_putchar_count(c, &j, count);
			write_space(j, count, flags.width);
			return ;
		}
		if (flags.minus == 0 && flags.width >= 0)
		{
			write_space(j, count, flags.width - 1);
			ft_putchar_count(c, &j, count);
			return ;
		}
		ft_putchar_count(c, &j, count);
		return ;
	}
}

char		*treat_flags_char(t_flags flags, char c)
{
	char	*to_print;

	if (flags.specifier == 'c' || (flags.specifier == '%' && flags.zero == 0))
		to_print = initialize_str(flags.width + 1);
	else
		to_print = initialize_str_zero(flags.width + 1);
	if (!to_print)
		return (NULL);
	if (flags.minus == 1)
		to_print[0] = c;
	else
		to_print[flags.width - 1] = c;
	return (to_print);
}

char		define_c(va_list pa, char specifier)
{
	char c;

	if (specifier == '%')
		c = '%';
	else
		c = va_arg(pa, int);
	return (c);
}

void		print_char(t_flags flags, va_list pa, int *count)
{
	char	c;
	int		len;
	char	*to_print;

	c = define_c(pa, flags.specifier);
	if (c == 0)
	{
		print_nullable_char(flags, c, count);
		return ;
	}
	if (flags.width == 0)
	{
		write(1, &c, 1);
		*count += 1;
		return ;
	}
	else
		to_print = treat_flags_char(flags, c);
	if (!to_print)
		return ;
	len = ft_strlen(to_print);
	*count += flags.width;
	ft_putstr(to_print);
	free(to_print);
}
