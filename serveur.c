/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:02:52 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 13:24:20 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char	*g_s = NULL;

void	signal_handler_len(int sign)
{
	static t_signal	_signal;
	static int		init = 0;

	if (!init)
	{
		_signal.c = 0;
		_signal.len = 0;
		_signal.i = 0;
		_signal.bit = 0;
		init = 1;
	}
	if (sign == SIGUSR2)
		_signal.len |= (1 << _signal.bit);
	_signal.bit++;
	if (_signal.bit >= 32)
	{
		g_s = ft_calloc((_signal.len) + 1, sizeof(char));
		if (NULL == g_s)
			exit(0);
		_signal.bit = 0;
		_signal.c = 0;
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
}

void	signal_handler(int sign)
{
	static t_signal	_signal;

	if (sign == SIGUSR2)
		_signal.c |= (1 << _signal.bit);
	_signal.bit ++;
	if (_signal.bit == 8)
	{
		if (_signal.c == '\0')
		{
			ft_printf("%s\n", g_s);
			free(g_s);
			_signal.c = 0;
			_signal.i = 0;
			g_s = NULL;
			signal(SIGUSR1, signal_handler_len);
			signal(SIGUSR2, signal_handler_len);
		}
		else
		{
			g_s[_signal.i] = _signal.c;
			_signal.i ++;
		}
		_signal.bit = 0;
		_signal.c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac > 1)
	{
		ft_printf("BAD PROSSESSOR\n");
		av[1] = 0;
		return (-1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, signal_handler_len);
	signal(SIGUSR2, signal_handler_len);
	while (1)
	{
	}
}
