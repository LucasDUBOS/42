/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:14:32 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/18 15:08:06 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				conversion(va_list *args, t_format *s)
{
	if (char_in_str("cC", s->conv))
	{
		if (stock_chr(args, s))
			return (1);
	}
	else if (char_in_str("Ddi", s->conv))
		stock_int(args, s);
	else if (char_in_str("oOuUxX", s->conv))
		stock_uint(args, s);
	else if (char_in_str("psS", s->conv))
	{
		if (stock_ptr(args, s))
			return (1);
	}
	else if (char_in_str("%", s->conv))
		s->tmp = ft_strdup("%");
	return (0);
}

int				stock_chr(va_list *args, t_format *s)
{
	int		i;

	i = 0;
	if ((s->conv == 'c' && s->modifier == MDF_L) || s->conv == 'C')
	{
		i = va_arg(*args, wchar_t);
		if ((s->tmp = ft_stockwchar(i)) == NULL)
			return (1);
	}
	if (s->conv == 'c' && s->modifier != MDF_L)
		s->tmp = ft_char_to_str(va_arg(*args, int));
	if (s->tmp[0] == '\0')
		s->tmp[0] = BACK_SLASH;
	return (0);
}

void			stock_int(va_list *args, t_format *s)
{
	if (s->modifier == MDF_HH)
		s->tmp = ft_itoa((signed char)va_arg(*args, long long int));
	else if (s->modifier == MDF_H)
		s->tmp = ft_itoa((short)va_arg(*args, long long int));
	else if (s->modifier == MDF_L || s->conv == 'D')
		s->tmp = ft_itoa((long)va_arg(*args, long long int));
	else if (s->modifier == MDF_LL)
		s->tmp = ft_itoa((long long)va_arg(*args, long long int));
	else if (s->modifier == MDF_J)
		s->tmp = ft_itoa((intmax_t)va_arg(*args, long long int));
	else if (s->modifier == MDF_Z)
		s->tmp = ft_itoa((size_t)va_arg(*args, long long int));
	else
		s->tmp = ft_itoa((int)va_arg(*args, long long int));
}

void			stock_uint(va_list *args, t_format *s)
{
	if (s->modifier == MDF_HH)
		s->tmp = ft_uitoa_base((UCHAR)va_arg(*args, uintmax_t), s->base);
	else if (s->modifier == MDF_H)
		s->tmp = ft_uitoa_base((USHORT)va_arg(*args, uintmax_t), s->base);
	else if (s->modifier == MDF_L)
		s->tmp = ft_uitoa_base((ULONG)va_arg(*args, uintmax_t), s->base);
	else if (s->modifier == MDF_LL)
		s->tmp = ft_uitoa_base((ULL)va_arg(*args, uintmax_t), s->base);
	else if (s->modifier == MDF_J)
		s->tmp = ft_uitoa_base((uintmax_t)va_arg(*args, uintmax_t), s->base);
	else if (s->modifier == MDF_Z)
		s->tmp = ft_uitoa_base((size_t)va_arg(*args, uintmax_t), s->base);
	else
		s->tmp = ft_uitoa_base((UINT)va_arg(*args, uintmax_t), s->base);
	if (s->conv == 'X')
		ft_putmaj(s->tmp);
}

int				stock_ptr(va_list *args, t_format *s)
{
	if ((s->conv == 's' && s->modifier == MDF_L) || s->conv == 'S')
	{
		if ((s->tmp = ft_stockwstr(va_arg(*args, wchar_t*))) == NULL)
			return (1);
	}
	else if (s->conv == 's')
	{
		if (s->precision == 2)
		{
			s->tmp = ft_strdup("\0");
			va_arg(*args, char*);
		}
		else
			s->tmp = ft_strdup(va_arg(*args, char*));
		if (s->tmp == NULL)
			s->tmp = ft_strdup("(null)");
	}
	else if (s->conv == 'p')
	{
		s->tmp = ft_strjoin3(ft_strdup("0x"),
		ft_uitoa_base(va_arg(*args, uintmax_t), 16));
	}
	return (0);
}
