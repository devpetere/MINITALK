/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:01:13 by herirand          #+#    #+#             */
/*   Updated: 2024/06/18 16:04:09 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.h"
#include <signal.h>

int	main(int ac, char **av)
{
	int						pid;
	static struct sigaction	sa;

	if (ac > 1)
	{
		ft_printf("ERROR\n");
		(void)av;
		return (0);
	}
	pid = getpid();
	ft_printf("MY PID = %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_len;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
