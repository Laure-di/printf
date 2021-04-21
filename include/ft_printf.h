/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:13:07 by lmasson           #+#    #+#             */
/*   Updated: 2021/04/21 14:16:50 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# define DECIMAL "0123456789"
# define HEXADECIMAL_MIN "0123456789abcdef"
# define HEXADECIMAL_MAJ "0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct		s_flags
{
	char			specifier;
	int				minus;
	int				zero;
	int				stars_width;
	int				stars_precision;
	int				width;
	int				dot;
	int				precision;
	int				minus_precision;
	va_list			pa;
	int				preci;
}					t_flags;

void				is_width(char c, t_flags *flags);
void				is_precision(char c, t_flags *flags);
void				initialize_flags(t_flags *flags);
void				check_flags(char *format, int *i, t_flags *flags);
t_flags				define_all_flags(char *format, int *i, va_list pa);
void				is_minus_precision(char c, t_flags *flags);
void				is_minus(char c, t_flags *flags);
void				is_stars_width(char c, t_flags *flags);
void				is_stars_precision(char c, t_flags *flags);
char				*ft_strdup(char *s1);
int					len_number_bis(unsigned long long int nbr, int base_len);
char				*ft_itoa_base(unsigned long long int nbr, char *base);
char				*ft_transform(long long nbr, t_flags flags);
void				write_space(int j, int *count, int width);
void				ft_putchar_count(char c, int *j, int *count);
void				print_nullable_char(t_flags flags, char c, int *count);
char				*treat_flags_char(t_flags flags, char c);
void				print_char(t_flags flags, va_list pa, int *count);
char				*higher_width(t_flags flags);
char				*create_to_print_hexa(t_flags flags, int len);
char				*treat_flags_hexa(t_flags flags, char *number, int *count);
void				print_hexa(va_list pa, t_flags *flags, int *count);
char				*treat_flags_int(t_flags *flags, char *number, int *count);
void				print_int(va_list pa, t_flags *flags, int *count);
char				*convert_pointer(t_flags flags, void *pointer);
char				*create_to_print_ptr(t_flags flags, int len);
char				*treat_flags_pointer(t_flags flags, char *to_transform,
					int *count);
void				print_pointer(va_list pa, t_flags *flags, int *count);
char				*width_lower_str(t_flags flags, int len, int *count);
char				*create_string(t_flags *flags, int len, int *count);
void				print_minus(t_flags flags, char *str, int len,
					char *to_print);
void				manage_flags_str(t_flags *flags, char *str, int len,
					int *count);
void				print_str(t_flags flags, va_list pa, int *count);
char				*higher_width_unsigned(t_flags flags);
char				*create_to_print_unsigned(t_flags flags, int len);
char				*treat_flags_unsigned(t_flags *flags, char *number,
					int *count);
char				*create_to_transform(t_flags *flags, unsigned nbr);
void				print_unsigned(va_list pa, t_flags *flags, int *count);
int					is_specifier(char c, char *specifier);
int					check_valid_specifier(char *format, int i, char *specifier);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strncpyend(char *dst, char *src, int len,
					int precision);
char				*ft_strncpy(char *dst, char *src, int n);
char				*ft_strcpyend(char *dst, char *src, int len);
char				*ft_strcpy(char *dst, char *src);
char				*initialize_str_zero(int size);
char				*initialize_str(int size);
int					ft_strlen(char *str);
int					is_alpha(char c);
int					is_digit(char c);
void				ft_putstr(char *str);
void				is_negative(char *dst, char *src, int *i, int *minus);
char				*ft_strcpy_int(char *dst, char *src, t_flags flags);
int					zero_fill(char *dst, char *src, int *len, int *count);
char				*ft_strcpyend_int(char *dst, char *src, int len,
					t_flags flags);
void				print(int *i, int *count, char c);
void				print_argument(t_flags *flags, va_list pa, int *count);
int					ft_printf(const char *format, ...);

#endif
