/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:55:57 by herirand          #+#    #+#             */
/*   Updated: 2024/06/18 16:04:31 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_H
# define USER_H

# include "../FT_PRINTF/ft_printf.h"
# include "../utils/utils.h"
# include <bits/types/siginfo_t.h>
# include <signal.h>

typedef struct s_signal
{
	int				bit;
	unsigned long	len;
	int				c;
	int				i;
}		t_signal;
void	init_signal(t_signal *s);
void	hundler_len(int si, t_signal *s);
void	signal_len(int sign, siginfo_t *info, void *ptr);
void	print_mess(t_signal *s, siginfo_t *info, struct sigaction *sa);
void	signal_mes(int sig, siginfo_t *info, void *ptr);
void	send_len(int n, int pid);
void	send_mess(char n, int pid);
void	receive(int s);

#endif
