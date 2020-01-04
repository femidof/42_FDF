/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:16 by oldurosi          #+#    #+#             */
/*   Updated: 2019/10/14 01:26:05 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*loc;

	loc = malloc(size);
	if (loc == NULL)
		return (NULL);
	ft_bzero(loc, size);
	return (loc);
}
