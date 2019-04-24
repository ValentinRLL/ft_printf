/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:47:26 by valecart          #+#    #+#             */
/*   Updated: 2019/04/24 16:21:24 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <string.h>

enum			e_flags
{
	_FLAG_SH = 0,
	_FLAG_0,
	_FLAG_M,
	_FLAG_P
};

# define MAX(a, b)	((a) > (b) ? (a) : (b))

# define FLAG_SH	(1 << _FLAG_SH)
# define FLAG_0		(1 << _FLAG_0)
# define FLAG_M		(1 << _FLAG_M)
# define FLAG_P		(1 << _FLAG_P)

# define CONV_CHARS	"cspdiouxX"
# define FLAG_CHARS	"#0-+"

typedef struct	s_conv_spec
{
	int			flags;
	int			field;
	int			precision;
	char		modifier;
	char		type;
	int			arg_index;
	int			size;
}				t_conv_spec;



size_t			num_len(long long n, int base);
void			ft_put_conv_spec(t_conv_spec *cspec, void *args, int *count);
void			ft_putlong_zeroes(long long n, int zeroes, char force);
t_conv_spec		*parse_conv_spec(char *format);
int				put_d(t_conv_spec *cspec, long long *args);
int				put_s(t_conv_spec *conv_spec, long long *args);
size_t			num_len(long long n, int base);
void			put_nchars(int n, char c);
void			ft_putlong_zeroes(long long n, int zeroes, char force);
long long		cast_long_long(t_conv_spec *cspec, long long val);

#endif
