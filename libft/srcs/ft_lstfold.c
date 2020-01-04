/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 02:16:51 by oldurosi          #+#    #+#             */
/*   Updated: 2019/10/15 22:14:11 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

void	*ft_lstfold(t_list *elem, void *(*f)(void *, void *, size_t))
{
	void	*result;

	if (!elem || !f)
		return (NULL);
	result = elem->content;
	while (elem)
	{
		if (elem->content && elem->next->content)
		{
			result = f(result, elem->next->content, elem->next->content_size);
		}
		elem = elem->next;
	}
	return (result);
}
