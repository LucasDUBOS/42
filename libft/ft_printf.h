/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:15:24 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/19 18:06:09 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define MDF_H		(0)
# define MDF_L		(1)
# define MDF_J		(2)
# define MDF_Z		(3)
# define MDF_HH		(10)
# define MDF_LL		(11)

# define BACK_SLASH (127)

# define UINT		unsigned int
# define ULONG		unsigned long
# define USHORT		unsigned short
# define UCHAR		unsigned char
# define ULL		unsigned long long

typedef struct	s_format
{
	char	*tmp;
	char	*str;
	int		k;
	char	conv;
	int		precision;
	int		att_plus;
	int		att_moins;
	int		att_esp;
	int		att_diese;
	int		att_zero;
	int		modifier;
	int		base;
	size_t	len;
}				t_format;

/*
** Fichier ft_printf.c
*/

int				ft_printf(const char *format, ...);
void			ft_printf2(t_format *s);
void			init(t_format *s);
int				developpement(va_list *args, const char *format, t_format *s);
int				developpement2(va_list *args, const char *format,
				int i, t_format *s);

/*
** Fichier analyse.c
*/

int				analyse(va_list *args, const char *format, t_format *s);
void			caractere_attribut1(const char *format, t_format *s);
void			caractere_attribut2(const char *format, t_format *s);

/*
** Fichier get_info.c
*/

void			get_info(const char *format, t_format *s);
void			get_conv(const char *str, t_format *s);
void			get_modifier(char *str, t_format *s);
void			get_attribut(char *str, t_format *s);
void			get_precision(char *str, t_format *s);

/*
** Fichier conversion.c
*/

int				conversion(va_list *args, t_format *s);
int				stock_chr(va_list *args, t_format *s);
void			stock_int(va_list *args, t_format *s);
void			stock_uint(va_list *args, t_format *s);
int				stock_ptr(va_list *args, t_format *s);

/*
** Fichier attributs.c
*/

void			attribut_plus(t_format *s);
void			attribut_esp(t_format *s);
void			attribut_diese(t_format *s);
void			attribut_zero(const char *format, t_format *s);
void			attribut_moins(const char *format, t_format *s);

/*
** Fichier largeur_de_champs.c
*/

void			largeur_champs(const char *format, t_format *s);

/*
** Fichier precison.c
*/

void			precision(const char *format, t_format *s);
void			precision_nbr(const char *format, t_format *s);
void			precision_str(const char *format, t_format *s);

#endif
