/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:34:11 by lmasson           #+#    #+#             */
/*   Updated: 2021/04/22 12:34:31 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_pointer(t_flags flags, void *pointer)
{
	char	*to_transform;
	char	*start;
	char	*final;

	start = "0x";
	if (pointer == 0 && flags.dot > 0)
		to_transform = initialize_str(1);
	else
		to_transform = ft_transform((unsigned long long)pointer, flags);
	if (!to_transform)
		return (NULL);
	final = ft_strjoin(start, to_transform);
	if (!final)
		return (NULL);
	free(to_transform);
	return (final);
}

char		*create_to_print_ptr(t_flags flags, int len)
{
	char	*to_print;

	if (flags.width <= len)
		to_print = initialize_str(len + 1);
	else
		to_print = initialize_str(flags.width + 1);
	if (!to_print)
		return (NULL);
	return (to_print);
}

char		*treat_flags_pointer(t_flags flags, char *to_transform,
		int *count)
{
	char	*to_print;
	int		len;
	int		len_total;

	len = ft_strlen(to_transform);
	to_print = create_to_print_ptr(flags, len);
	if (!to_print)
		return (NULL);
	len_total = ft_strlen(to_print);
	*count += len_total;
	if (flags.minus == 1)
		ft_strcpy(to_print, to_transform);
	else
		ft_strcpyend(to_print, to_transform, len_total);
	return (to_print);
}

void		print_pointer(va_list pa, t_flags *flags, int *count)
{
	void	*pointer;
	char	*to_transform;
	char	*to_print;

	pointer = va_arg(pa, void*);
	to_transform = convert_pointer(*flags, pointer);
	to_print = treat_flags_pointer(*flags, to_transform, count);
	if (!to_print)
		return ;
	ft_putstr(to_print);
	free(to_transform);
	free(to_print);
}
