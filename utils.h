/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:06:58 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 09:41:03 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
