/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:12:31 by herirand          #+#    #+#             */
/*   Updated: 2024/06/18 16:01:48 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <unistd.h>

char	*g_s = NULL;

void	init_signal(t_signal *s)
{
	s->c = 0;
	s->bit = 0;
	s->len = 0;
	s->i = 0;
}

void	hundler_len(int si, t_signal *s)
{
	if (si == SIGUSR2)
		s->len |= 1 << s->bit;
	s->bit++;
}

void	signal_len(int sign, siginfo_t *info, void *ptr)
{
	static t_signal			s;
	static struct sigaction	sa;
	static int				init = 0;

	(void)ptr;
	(void)info;
	if (!init)
	{
		init_signal(&s);
		init = 1;
	}
	hundler_len(sign, &s);
	if (s.bit >= 32)
	{
		g_s = (char *)ft_calloc(s.len + 1, sizeof(char));
		if (NULL == g_s)
			exit(0);
		s.bit = 0;
		s.c = 0;
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = signal_mes;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}

void	print_mess(t_signal *s, siginfo_t *info, struct sigaction *sa)
{
	ft_printf("%s\n", g_s);
	kill(info->si_pid, SIGUSR2);
	free(g_s);
	s->c = 0;
	s->i = 0;
	g_s = NULL;
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = signal_len;
	sigaction(SIGUSR1, sa, NULL);
	sigaction(SIGUSR2, sa, NULL);
}

void	signal_mes(int sign, siginfo_t *info, void *ptr)
{
	static t_signal			s;
	static struct sigaction	sa;

	(void)ptr;
	if (sign == SIGUSR2)
		s.c |= (1 << s.bit);
	s.bit++;
	if (s.bit == 8)
	{
		if (s.c == '\0')
			print_mess(&s, info, &sa);
		else
		{
			g_s[s.i] = s.c;
			s.i ++;
		}
		s.bit = 0;
		s.c = 0;
	}
}
