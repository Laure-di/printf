/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:02:06 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/21 13:54:04 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*higher_width_unsigned(t_flags flags)
{
	char	*to_print;

	if (flags.zero == 1)
	{
		if (flags.precision <= flags.width)
			to_print = initialize_str_zero(flags.width + 1);
		else
			to_print = initialize_str_zero(flags.precision + 1);
	}
	else
	{
		if (flags.width <= flags.precision)
			to_print = initialize_str(flags.precision + 1);
		else
			to_print = initialize_str(flags.width + 1);
	}
	return (to_print);
}

char		*create_to_print_unsigned(t_flags flags, int len)
{
	char *to_print;

	if (len < flags.width)
		to_print = higher_width_unsigned(flags);
	else
	{
		if (flags.zero == 1)
		{
			if (flags.precision < len)
				to_print = initialize_str_zero(len + 1);
			else
				to_print = initialize_str_zero(flags.precision + 1);
		}
		else
		{
			if (len <= flags.precision)
				to_print = initialize_str(flags.precision + 1);
			else
				to_print = initialize_str(len + 1);
		}
	}
	return (to_print);
}

char		*treat_flags_unsigned(t_flags *flags, char *number, int *count)
{
	char	*to_print;
	int		len;
	int		len_final;

	len = ft_strlen(number);
	to_print = create_to_print_unsigned(*flags, len);
	len_final = ft_strlen(to_print);
	*count += len_final;
	if (len <= flags->precision)
	{
		if (flags->minus == 1)
			ft_strcpy_int(to_print, number, *flags);
		else
			ft_strcpyend_int(to_print, number, len_final, *flags);
	}
	else
	{
		if (flags->minus == 1)
			ft_strcpy(to_print, number);
		else
			ft_strcpyend(to_print, number, len_final);
	}
	return (to_print);
}

char		*create_to_transform(t_flags *flags, unsigned nbr)
{
	char	*to_transform;

	if (nbr == 0 && flags->dot > 0 && 0 <= flags->precision)
	{
		to_transform = initialize_str(1);
		flags->zero = 0;
	}
	else
		to_transform = ft_transform((unsigned long long)nbr, *flags);
	return (to_transform);
}

void		print_unsigned(va_list pa, t_flags *flags, int *count)
{
	unsigned	nbr;
	char		*to_print;
	char		*to_transform;
	int			len;

	nbr = va_arg(pa, unsigned);
	len = 0;
	if (!nbr)
		nbr = 0;
	to_transform = create_to_transform(flags, nbr);
	if (!to_transform)
		return ;
	len = ft_strlen(to_transform);
	if (len < flags->width && flags->precision < flags->width &&
			nbr != 0 && flags->dot > 0 && 0 <= flags->precision)
		flags->zero = 0;
	to_print = treat_flags_unsigned(flags, to_transform, count);
	ft_putstr(to_print);
	free(to_transform);
	free(to_print);
}
