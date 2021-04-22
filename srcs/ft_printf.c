/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:46:02 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/22 13:28:06 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_argument(t_flags *flags, va_list pa, int *count)
{
	if (flags->specifier == 'c' || flags->specifier == '%')
		print_char(*flags, pa, count);
	if (flags->specifier == 's')
		print_str(*flags, pa, count);
	if (flags->specifier == 'p')
		print_pointer(pa, flags, count);
	if (flags->specifier == 'x' || flags->specifier == 'X')
		print_hexa(pa, flags, count);
	if (flags->specifier == 'd' || flags->specifier == 'i')
		print_int(pa, flags, count);
	if (flags->specifier == 'u')
		print_unsigned(pa, flags, count);
}

int			ft_printf(const char *format, ...)
{
	va_list	pa;
	int		i;
	int		count;
	char	*str;
	t_flags	flags;

	i = 0;
	count = 0;
	va_start(pa, format);
	str = (char*)format;
	while (str[i])
	{
		if (str[i] == '%' && check_valid_specifier(str, i++, &flags.specifier))
		{
			flags = define_all_flags(str, &i, pa);
			print_argument(&flags, pa, &count);
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(pa);
	return (count);
}
