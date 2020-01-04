/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:26:10 by oldurosi          #+#    #+#             */
/*   Updated: 2019/10/15 10:52:51 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	if (dst == src)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		cdst = (unsigned char*)dst;
		csrc = (unsigned char *)src;
		i = 0;
		while (len > 0)
		{
			len--;
			cdst[len] = csrc[len];
		}
	}
	return (dst);
}
