/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:48:21 by herirand          #+#    #+#             */
/*   Updated: 2024/03/28 11:30:17 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *cnt)
{
	write (1, &c, 1);
	*cnt = *cnt + 1;
}

static void	check_next(char format, int *cnt, va_list arg)
{
	if (format == 'c')
		ft_print_char(va_arg(arg, int), cnt);
	else if (format == 's')
		ft_print_str(va_arg(arg, char *), cnt);
	else if (format == 'p')
		ft_print_p(va_arg(arg, void *), cnt);
	else if (format == 'd' || format == 'i')
		ft_print_d(va_arg(arg, int), format, cnt);
	else if (format == 'u')
		ft_print_ud(va_arg(arg, unsigned int), cnt);
	else if (format == 'x' || format == 'X')
		ft_print_hex(va_arg(arg, unsigned int), format, cnt);
	else if (format == '%')
		ft_print_char('%', cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		cnt;

	va_start (arg, format);
	i = 0;
	cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
			check_next(format[++i], &cnt, arg);
		else
			ft_print_char(format[i], &cnt);
		i ++;
	}
	va_end(arg);
	return (cnt);
}
