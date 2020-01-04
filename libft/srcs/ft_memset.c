/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:03:01 by oldurosi          #+#    #+#             */
/*   Updated: 2019/09/24 21:36:02 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*xb;

	i = 0;
	xb = (unsigned char *)b;
	while (len--)
	{
		xb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
