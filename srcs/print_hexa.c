/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:28:29 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/22 12:32:19 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*higher_width(t_flags flags)
{
	char	*to_print;

	if (flags.zero == 1)
		to_print = initialize_str_zero(flags.width + 1);
	else
	{
		if (flags.width <= flags.precision)
			to_print = initialize_str(flags.precision + 1);
		else
			to_print = initialize_str(flags.width + 1);
	}
	if (!to_print)
		return (NULL);
	return (to_print);
}

char		*create_to_print_hexa(t_flags flags, int len)
{
	char		*to_print;

	if (len <= flags.width)
		to_print = higher_width(flags);
	else
	{
		if (flags.zero == 1)
			to_print = initialize_str_zero(len + 1);
		else
		{
			if (len <= flags.precision)
				to_print = initialize_str(flags.precision + 1);
			else
				to_print = initialize_str(len + 1);
		}
	}
	if (!to_print)
		return (NULL);
	return (to_print);
}

char		*treat_flags_hexa(t_flags flags, char *number, int *count)
{
	char		*to_print;
	int			len;
	int			len_final;

	len = ft_strlen(number);
	to_print = create_to_print_hexa(flags, len);
	if (!to_print)
		return (NULL);
	len_final = ft_strlen(to_print);
	*count += len_final;
	if (len <= flags.precision)
	{
		if (flags.minus == 1)
			ft_strcpy_int(to_print, number, flags);
		else
			ft_strcpyend_int(to_print, number, len_final, flags);
	}
	else
	{
		if (flags.minus == 1)
			ft_strcpy(to_print, number);
		else
			ft_strcpyend(to_print, number, len_final);
	}
	return (to_print);
}

void		print_hexa(va_list pa, t_flags *flags, int *count)
{
	unsigned int	nbr;
	char			*hexa;
	char			*to_print;

	nbr = va_arg(pa, unsigned int);
	if (!nbr)
		nbr = 0;
	if (flags->dot > 0 && 0 <= flags->precision)
		flags->zero = 0;
	if (nbr == 0 && flags->dot > 0 && 0 <= flags->precision)
		hexa = initialize_str(1);
	else
		hexa = ft_transform((long long)nbr, *flags);
	if (!hexa)
		return ;
	to_print = treat_flags_hexa(*flags, hexa, count);
	if (!to_print)
		return ;
	ft_putstr(to_print);
	free(hexa);
	free(to_print);
}
