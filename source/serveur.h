/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:11:07 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 13:57:02 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include "../FT_PRINTF/ft_printf.h"
# include "../utils/utils.h"
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_signal
{
	int				bit;
	unsigned long	len;
	int				c;
	int				i;
}		t_signal;

void	signal_handler(int signal);
void	gestion_signal(int pid, char c);
void	signal_handler_len(int sign);
void	send_integer(int pid, int n);
void	send_len_and_mess(char *av, int pid);

#endif
