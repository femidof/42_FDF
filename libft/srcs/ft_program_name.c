/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:26:57 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/03 20:27:17 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char *ft_program_name(char const *argv0)
{
    char *name;

    name  = (char *)argv0;
    while (*name && *name != '/')
    {
        name++;
    }
    if (!name)
        return ((char *)argv0);
    return (name + 1);
}
