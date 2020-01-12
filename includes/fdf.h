/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:08:53 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/03 21:08:54 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"
#include "../minilibx/mlx.h"

# define P_WIDTH  1920 //1280 540.85
# define P_HEIGHT 1080 //720  304.22
# define XY_ZOOM 0.005
# define Z_ZOOM 0.005

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;
typedef struct	s_map
{
	int		**values;
	int		length;
	int		breadth;
	int		coord_x;
	int		coord_y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		zoom;
	int		isometric;
	double	z_value;
	double	angle_x;
	double	angle_y;
}				t_map;
typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
	t_color	color;
}				t_fdf;

void read_lines(char *argv, t_fdf *fdf);

#endif
