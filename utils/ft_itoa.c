/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42Antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:01:05 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 09:38:52 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_length(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i ++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i ++;
	}
	return (i);
}

static char	*empt(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int long	nb;
	char		*new;
	int			len;
	int			i;

	len = ft_length(n);
	nb = n;
	if (n < 0)
		nb = -nb;
	if (n == 0)
		return (empt());
	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		new[i] = nb % 10 + '0';
		nb = nb / 10;
		i --;
	}
	if (n < 0)
		new[0] = '-';
	return (new);
}
