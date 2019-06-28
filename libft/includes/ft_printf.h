/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:39:39 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 20:35:17 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define B_RED "\x1b[31;1m"
# define B_GREEN "\x1b[32;1m"
# define B_YELLOW "\x1b[33;1m"
# define B_BLUE "\x1b[34;1m"
# define B_MAGENTA "\x1b[35;1m"
# define B_CYAN "\x1b[36;1m"
# define B_WHITE "\x1b[37;1m"
# define EOC "\x1b[0m"

typedef struct		s_orgi
{
	int				len;
	char			h;
	char			hh;
	char			l;
	char			ll;
	char			bigl;
	char			dot;
	unsigned int	precision;
	unsigned int	width;
	char			sharp;
	char			minus;
	char			zero;
	char			plus;
	char			space;
	char			type;
}					t_orgi;

int					ft_printf(const char *format, ...);
int					parse_this(va_list var, t_orgi *params);
char				*s_type(char *str, t_orgi *params);
char				*c_type(char c, t_orgi *params);
char				*d_type(va_list var, t_orgi *params);
char				*o_type(va_list var, t_orgi *params);
char				*u_type(t_orgi *params, va_list var);
char				*x_type(va_list var, t_orgi *params);
char				*p_type(va_list var, t_orgi *params);
char				*f_type(va_list var, t_orgi *params);
char				*paste_start(char *str, char c);
void				get_modifier(const char *format, int nargs, t_orgi *params);
void				get_width(const char *format, int nargs, t_orgi *params);
void				null_all(t_orgi *params);
char				*percent_manages(t_orgi *params);
char				*implement_width(char *str, int width, t_orgi *params);
char				*implement_precision(char *str, t_orgi *params);
char				*implement_sign(char *str,
					long long int nb, t_orgi *params);
char				*check_on_plus(long long int nb, t_orgi *params);

#endif
