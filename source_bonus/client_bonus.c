/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:20 by herirand          #+#    #+#             */
/*   Updated: 2024/06/14 15:45:27 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.h"
#include <signal.h>
#include <unistd.h>

void	send_len(int len, int pid)
{
	int	bits;

	bits = 0;
	while (bits < 32)
	{
		if (len & (1 << bits))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bits ++;
	}
}

void	send_mess(char n, int pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (n & (1 << bits))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		bits ++;
	}
}

void	receive(int s)
{
	if (s == SIGUSR2)
		ft_printf("Message envoyer avec succes !");
}

int	main(int ac, char **av)
{
	int		pid;
	int		len;
	int		i;

	signal(SIGUSR2, receive);
	if (ac != 3)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	len = ft_strlen(av[2]);
	pid = ft_atoi(av[1]);
	send_len(len, pid);
	i = 0;
	while (av[2][i])
	{
		send_mess(av[2][i], pid);
		i ++;
	}
	send_mess('\0', pid);
	return (0);
}
