/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:21 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/20 15:30:24 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	mix_color(t_fdf *fdf)
{
	fdf->color.r = (rand() % 0x7f);
	fdf->color.g = (rand() % 0x7f);
	fdf->color.b = (rand() % 0x7f);
}

void	nomalize_map(t_fdf *fdf)
{
	fdf->map.coord_x = 0;
	fdf->map.coord_y = 0;
	fdf->map.z_value = 1.00;
	fdf->map.angle_x = cos(M_PI / 3);
	fdf->map.angle_y = fdf->map.angle_x * sin(M_PI / 6);
	fdf->map.scalin = ceil((fdf->map.length > fdf->map.breadth)) \
		? (P_WIDTH / fdf->map.length) + MAGNIFY \
		: (P_HEIGHT / fdf->map.breadth) + MAGNIFY;
	fdf->map.isometric = 1;
	fdf->color.r = 0x4F;
	fdf->color.g = 0x4F;
	fdf->color.b = 0x4F;
}

void	get_values(t_fdf *fdf, int x, int y, char *line)
{
	int		i;
	char	**splitted_value;

	if ((splitted_value = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (splitted_value[i] && (x != fdf->map.length))
		{
			fdf->map.values[y][x] = ft_atoi(splitted_value[i++]);
			x++;
		}
		free(splitted_value);
	}
}
