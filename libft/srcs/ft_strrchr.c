/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:50:29 by oldurosi          #+#    #+#             */
/*   Updated: 2019/09/18 13:57:51 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = ft_strlen(s);
	j = 0;
	while (i >= j)
		if (s[i - j++] == (char)c)
			return ((char*)&s[i - (j - 1)]);
	return (NULL);
}
