/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:37:04 by oldurosi          #+#    #+#             */
/*   Updated: 2019/09/18 22:51:38 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*xdst;
	unsigned char	*xsrc;

	xdst = (unsigned char *)dst;
	xsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		xdst[i] = xsrc[i];
		if (xsrc[i] == (unsigned char)c)
			return (&xdst[i + 1]);
		i++;
	}
	return (NULL);
}
