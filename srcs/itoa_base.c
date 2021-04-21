/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:54:00 by lauremass         #+#    #+#             */
/*   Updated: 2021/04/21 14:14:27 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*s1_copy;

	len = ft_strlen(s1) + 1;
	i = 0;
	s1_copy = malloc((sizeof(char) * len));
	if (!s1_copy)
		return (NULL);
	while (s1[i])
	{
		s1_copy[i] = s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}

int		len_number_bis(unsigned long long int nbr, int base_len)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr < 0)
	{
		nbr = (-1) * nbr;
		nbr_len++;
	}
	while (0 < nbr)
	{
		nbr = nbr / base_len;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa_base(unsigned long long int nbr, char *base)
{
	int		base_len;
	int		nbr_len;
	char	*str_bis;
	int		i;

	base_len = ft_strlen(base);
	nbr_len = len_number_bis(nbr, base_len);
	i = nbr_len;
	if (nbr == 0)
		return (ft_strdup("0"));
	str_bis = initialize_str(nbr_len + 1);
	if (!str_bis)
		return (NULL);
	str_bis[i--] = '\0';
	while (0 < nbr)
	{
		str_bis[i--] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	return (str_bis);
}

char	*ft_transform(long long nbr, t_flags flags)
{
	int		minus;
	char	*str;
	char	*final;

	minus = 0;
	if (nbr < 0)
	{
		minus = 1;
		if (flags.specifier == 'i' || flags.specifier == 'd')
			nbr = nbr * (-1);
	}
	if (flags.specifier == 'u' || flags.specifier == 'i' ||
			flags.specifier == 'd')
		str = ft_itoa_base((unsigned long long)nbr, DECIMAL);
	if (flags.specifier == 'x' || flags.specifier == 'p')
		str = ft_itoa_base((unsigned long long)nbr, HEXADECIMAL_MIN);
	if (flags.specifier == 'X')
		str = ft_itoa_base((unsigned long long)nbr, HEXADECIMAL_MAJ);
	if (minus == 1 && flags.specifier != 'p')
		final = ft_strjoin("-", str);
	else
		return (str);
	free(str);
	return (final);
}
