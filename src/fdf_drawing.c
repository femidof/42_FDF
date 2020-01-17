/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:19:09 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/16 20:25:17 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void draw(t_fdf *fdf, int x, int y, double dchang)
{
	int point;

	if ((x > 0 && y > 0) && (x < P_WIDTH && y < P_HEIGHT))
	{
		point = (x * 4) + (y * P_WIDTH * 4);
		fdf->image.data[point] = fdf->color.R + dchang;
		fdf->image.data[point + 1] = fdf->color.G + dchang;
		fdf->image.data[point + 2] = fdf->color.B + dchang;
		fdf->image.data[point + 3] = 0x4f + dchang;
	}
}

static void draw_pix(t_fdf *fdf)
{
	double x;
	double y;
	double dx;
	double dy;
	double dchang;

	x = fdf->map.x0;
	y = fdf->map.y0;
	dx = fdf->map.x1 - fdf->map.x0;
	dy = fdf->map.y1 - fdf->map.y0;
	dchang = sqrt((pow(dx, 2)) + (pow(dy, 2)));
	dx /= dchang;
	dy /= dchang;
	while (dchang > 0)
	{
		draw(fdf, x, y, dchang);
		x += dx;
		y += dy;
		dchang -= 1;
	}
}

static void draw_to_xaxis(t_fdf *fdf, int x, int  y)
{
	int dx;
	int dy;

	dx = x - fdf->map.length / 2;
	dy = y - fdf->map.breadth / 2;
	fdf->map.x0 = fdf->map.angle_x * (dx - dy) * fdf->map.scalin;
	fdf->map.y0 = fdf->map.angle_y * (dx + dy) * fdf->map.scalin;
	fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.z_value;
	fdf->map.x1 = fdf->map.angle_x * ((dx + 1) - dy) * fdf->map.scalin;
	fdf->map.y1 = fdf->map.angle_y * ((dx + 1) + dy) * fdf->map.scalin;
	fdf->map.y1 -= fdf->map.values[y][x + 1] * fdf->map.z_value;
	fdf->map.x0 += (P_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y0 += (P_HEIGHT / 2) + fdf->map.coord_y;
	fdf->map.x1 += (P_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y1 += (P_HEIGHT / 2) + fdf->map.coord_y;
	draw_pix(fdf);
}

static void draw_to_yaxis(t_fdf *fdf, int x, int  y)
{
	int dx;
	int dy;

	dx = x - fdf->map.length / 2;
	dy = y - fdf->map.breadth / 2;
	fdf->map.x0 = fdf->map.angle_x * (dx - dy) * fdf->map.scalin;
	fdf->map.y0 = fdf->map.angle_y * (dx + dy) * fdf->map.scalin;
	fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.z_value;
	fdf->map.x1 = fdf->map.angle_x * (dx - (dy + 1)) * fdf->map.scalin;
	fdf->map.y1 = fdf->map.angle_y * (dx + (dy + 1)) * fdf->map.scalin;
	fdf->map.y1 -= fdf->map.values[y + 1][x] * fdf->map.z_value;
	fdf->map.x0 += (P_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y0 += (P_HEIGHT / 2) + fdf->map.coord_y;
	fdf->map.x1 += (P_WIDTH / 2) + fdf->map.coord_x;
	fdf->map.y1 += (P_HEIGHT / 2) + fdf->map.coord_y;
	draw_pix(fdf);
}

int fdf_draw(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, P_WIDTH, P_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
			&fdf->image.size, &fdf->image.endian);
	while (fdf->map.breadth > y)
	{
		x = 0;
		while (fdf->map.length > x)
		{
			fdf->map.x0 = x;
			fdf->map.y0 = y;
			if (fdf->map.length > x + 1)
				draw_to_xaxis(fdf, x, y);
			if (fdf->map.breadth > y + 1)
				draw_to_yaxis(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	return (0);
}
