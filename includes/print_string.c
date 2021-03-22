/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:16:36 by lauremass         #+#    #+#             */
/*   Updated: 2021/03/22 17:08:23 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_lower_str(t_flags flags, int len, int *count)
{
	char *to_print;

	if (flags.precision < len && flags.dot > 0)
	{
		if (flags.precision >= 0 && flags.width > 0 && flags.precision < len
				&& flags.precision < flags.width)
		{
			to_print = initialize_str(flags.width + 1);
			*count += flags.width;
		}
		else
		{
			to_print = initialize_str(flags.precision + 1);
			*count += flags.precision;
		}
		return (to_print);
	}
	to_print = initialize_str(len + 1);
	*count += len;
	return (to_print);
}

char	*create_string(t_flags *flags, int len, int *count)
{
	char	*to_print;

	if (len < flags->precision || flags->precision == -1)
		flags->precision = len;
	if (flags->width < len && flags->precision >= 0)
		to_print = width_lower_str(*flags, len, count);
	else
	{
		to_print = initialize_str(flags->width + 1);
		*count += flags->width;
	}
	return (to_print);
}

void	print_minus(t_flags flags, char *str, int len, char *to_print)
{
	if (flags.precision >= 0 && flags.dot > 0 && flags.precision < len)
	{
		to_print = ft_strncpy(to_print, str, flags.precision);
		ft_putstr(to_print);
		free(to_print);
		return ;
	}
	to_print = ft_strcpy(to_print, str);
	ft_putstr(to_print);
	free(to_print);
}

void	manage_flags_str(t_flags *flags, char *str, int len, int *count)
{
	char	*to_print;
	int		width;

	to_print = create_string(flags, len, count);
	width = ft_strlen(to_print);
	if (flags->minus == 1)
		print_minus(*flags, str, len, to_print);
	else
	{
		if (flags->precision >= 0 && flags->dot > 0)
		{
			to_print = ft_strncpyend(to_print, str, width, flags->precision);
			ft_putstr(to_print);
			free(to_print);
			return ;
		}
		to_print = ft_strcpyend(to_print, str, width);
		ft_putstr(to_print);
		free(to_print);
	}
}

void	print_str(t_flags flags, va_list pa, int *count)
{
	char	*str;
	int		j;
	int		len;

	j = 0;
	str = va_arg(pa, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len == 0 && flags.width == 0)
		return ;
	manage_flags_str(&flags, str, len, count);
}
