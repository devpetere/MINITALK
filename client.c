/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:26:42 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 13:15:43 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	gestion_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit ++;
	}
}

void	send_integer(int pid, int n)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if (n &(1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit ++;
	}
}

int	main(int ac, char **av)

{
	int		i;
	int		pid;
	int		len;

	if (ac != 3)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	send_integer(pid, len);
	i = 0;
	while (av[2][i])
	{
		gestion_signal(pid, av[2][i]);
		i ++;
	}
	gestion_signal(pid, '\0');
}
