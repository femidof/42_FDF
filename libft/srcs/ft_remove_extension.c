/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:44:24 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/09 17:44:28 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char	*ft_remove_extension(char *filename)
{
	char	*b_name;
	char	*dot;
	char	*sep;

	if (!filename)
	{
		return (NULL);
	}
	if (!(b_name = (char *)malloc(sizeof(char) * ft_strlen(filename) + 1)))
		return (NULL);
	ft_strcpy(b_name, filename);
	if ((dot = ft_strrchr(b_name, '.')))
	{
		if ((sep = ft_strrchr(b_name, '/')))
			(sep < dot) ? *dot = '\0' : *dot;
		else
			*dot = '\0';
	}
	return (b_name);
}
