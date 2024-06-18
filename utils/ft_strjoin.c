/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42Antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:38:27 by herirand          #+#    #+#             */
/*   Updated: 2024/06/13 09:08:18 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i] != '\0')
			new[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			new[j++] = s2[i++];
		new[j] = '\0';
		return (new);
	}
	return (NULL);
}
