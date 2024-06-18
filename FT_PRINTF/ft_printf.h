/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:07:01 by herirand          #+#    #+#             */
/*   Updated: 2024/03/28 11:29:55 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_print_char(char n, int *cnt);
void	ft_print_str(char *s, int *cnt);
void	ft_print_hex(unsigned long nb, char c, int *cnt);
void	ft_print_d(long int n, char c, int *cnt);
void	ft_print_p(void *n, int *cnt);
void	ft_print_ud(unsigned int n, int *cnt);

#endif
