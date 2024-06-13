/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42Antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:11:28 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 09:09:52 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	cnt;

	cnt = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i ++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i ++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		cnt = (cnt * 10) + (nptr[i] - '0');
		i ++;
	}
	return (cnt * sign);
}
