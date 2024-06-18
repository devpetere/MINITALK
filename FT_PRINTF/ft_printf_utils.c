/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:07:01 by herirand          #+#    #+#             */
/*   Updated: 2024/03/28 13:15:10 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, int *cnt)
{
	int	i;

	if (s == NULL)
	{
		write (1, "(null)", 6);
		*cnt += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_print_char(s[i], cnt);
		i ++;
	}
}

void	ft_print_hex(unsigned long nb, char c, int *cnt)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (c == 'x')
		s = "0123456789abcdef";
	if (nb > 15)
		ft_print_hex(nb / 16, c, cnt);
	ft_print_char(s[nb % 16], cnt);
}

void	ft_print_d(long int n, char c, int *cnt)
{
	if (c == 'd' || c == 'i')
	{
		if (n < 0)
		{
			ft_print_char('-', cnt);
			n = -n;
		}
		if (n > 9)
			ft_print_d(n / 10, c, cnt);
		ft_print_char((n % 10) + '0', cnt);
	}
}

void	ft_print_ud(unsigned int n, int *cnt)
{
	unsigned long	nb;

	nb = n;
	if (nb > 9)
		ft_print_ud(nb / 10, cnt);
	ft_print_char((nb % 10) + '0', cnt);
}

void	ft_print_p(void *n, int *cnt)
{
	unsigned long	nb;

	if (n == NULL)
	{
		ft_print_str("(nil)", cnt);
		return ;
	}
	nb = (unsigned long)n;
	ft_print_str("0x", cnt);
	ft_print_hex(nb, 'x', cnt);
}
