/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:28:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/23 18:24:32 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_list		*parse_format(char *format)
{
	t_list		*lst;
	t_conv_spec	*cspec;

	lst = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			cspec = parse_conv_spec(format + 1);
			ft_lstpushback(lst, cspec, sizeof(t_conv_spec));
			format += cspec->size;
		}
		else
			format++;
	}
	return (lst);
}

t_conv_spec	*parse_conv_spec(char *format)
{
	t_conv_spec	*conv_spec;

	return (conv_spec);
}
