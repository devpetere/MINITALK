/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42Antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:22:06 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 09:39:36 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*now;

	now = (char *) malloc (nmemb * size);
	if (now == NULL)
		return (NULL);
	ft_bzero(now, size * nmemb);
	return ((void *) now);
}
