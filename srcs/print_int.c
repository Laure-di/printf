/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:51:31 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/22 12:32:57 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*treat_flags_int(t_flags *flags, char *number, int *count)
{
	char	*to_print;
	int		len;
	int		len_final;

	len = ft_strlen(number);
	to_print = create_to_print_hexa(*flags, len);
	if (!to_print)
		return (NULL);
	len_final = ft_strlen(to_print);
	*count += len_final;
	if (len <= flags->precision || (flags->zero == 1 && number[0] == '-'))
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

void		print_int(va_list pa, t_flags *flags, int *count)
{
	int		nbr;
	char	*number;
	char	*to_print;

	nbr = va_arg(pa, int);
	if (!nbr)
		nbr = 0;
	if (nbr < 0 && flags->precision > -1)
		flags->precision += 1;
	if ((flags->dot > 0 && flags->precision > -1) ||
			(flags->minus == 1 && flags->zero == 1))
		flags->zero = 0;
	if (nbr == 0 && flags->dot > 0 && flags->precision > -1)
		number = initialize_str(1);
	else
		number = ft_transform((unsigned long long)nbr, *flags);
	if (!number)
		return ;
	to_print = treat_flags_int(flags, number, count);
	if (!to_print)
		return ;
	ft_putstr(to_print);
	free(to_print);
	free(number);
}
