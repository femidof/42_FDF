/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:41:43 by oldurosi          #+#    #+#             */
/*   Updated: 2019/10/15 08:25:24 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char	*ft_strstr(const char *hystk, const char *ndle)
{
	int i;
	int j;

	i = 0;
	if (!(*ndle))
		return ((char*)hystk);
	while (hystk[i])
	{
		if (hystk[i] == ndle[0])
		{
			j = 1;
			while (ndle[j] != '\0' && hystk[i + j] == ndle[j])
				++j;
			if (ndle[j] == '\0')
				return ((char*)&hystk[i]);
		}
		i++;
	}
	return (0);
}
