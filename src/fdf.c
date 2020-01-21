/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:15:51 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/21 00:02:27 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		nomalize_map(fdf);
	else if (keycode == KEY_UPARROW)
		fdf->map.coord_y -= 2;
	else if (keycode == KEY_DOWNARROW)
		fdf->map.coord_y += 2;
	else if (keycode == KEY_LEFTARROW)
		fdf->map.coord_x -= 3;
	else if (keycode == KEY_RIGHTARROW)
		fdf->map.coord_x += 3;
	else if (keycode == KEY_ANSI_Q)
		fdf->map.scalin += 1;
	else if (keycode == KEY_ANSI_A)
		fdf->map.scalin -= 1;
	else if (keycode == KEY_ANSI_W)
		fdf->map.z_value += 0.25;
	else if (keycode == KEY_ANSI_S)
		fdf->map.z_value -= 0.25;
	else if (keycode == KEY_ANSI_C)
		fdf->map.angle_y *= (fdf->map.isometric++ % 2) ? 0.5 : 2;
	else if (keycode == KEY_ANSI_E)
		mix_color(fdf);
	return (0);
}

/*
**  Here please note that x ---- length which is the amount on a side
**  while y ---- is the amount of rows we have and this can be called breadth
*/

void		fdf_read(char *argv, t_fdf *fdf)
{
	int		fd;
	int		x;
	char	*line;
	int		y;

	x = 0;
	y = 0;
	fdf->map.breadth = line_count(argv, fdf);
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Error opening file!", 1);
	if (!(fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.breadth)))
		ft_puterror("Memory Allocation failed!", 3);
	while (get_next_line(fd, &line) == 1 && y != fdf->map.breadth)
	{
		if (!(fdf->map.values[y] = (int *)malloc(sizeof(int) * \
						fdf->map.length)))
			ft_puterror("Memory Allocation failed!", 3);
		validate_lines(line);
		get_values(fdf, x, y, line);
		x = 0;
		y++;
		free(line);
	}
	if (close(fd) == -1)
		ft_puterror("Error closing the file!", 2);
}

void		read_lines(char *argv0, t_fdf *fdf)
{
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		ft_puterror("Memory Allocation failed!", 3);
	fdf_read(argv0, fdf);
	nomalize_map(fdf);
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, P_WIDTH, P_HEIGHT, \
			ft_strjoin(ft_remove_extension(\
			ft_program_name(&argv0[1])), " FDF"));
	mlx_hook(fdf->mlx.win, 2, 3, fdf_keys, fdf);
	mlx_loop_hook(fdf->mlx.init, fdf_draw, fdf);
	mlx_loop(fdf->mlx.init);
}

/*
**  Shows how to run and use fdf
*/

void		usage(char *argv0)
{
	ft_putstr("\033[0;31mError:\033[0mInvalid file input \n");
	ft_putstr("\033[01;33mUsage:\n\t\033[0m");
	ft_putstr(ft_program_name(argv0));
	ft_putstr(" fdf_file\n");
	ft_putstr("\033[1;35mControls:\n\033[0m");
	ft_putstr("\t[Esc]        -> Exit the program.\n");
	ft_putstr("\t[R]          -> Reset the map.\n");
	ft_putstr("\t[E]          -> Color the map!.\n");
	ft_putstr("\t[Q][A]       -> Zoom in and zoom out.\n");
	ft_putstr("\t[W][S]       -> Altitude \n");
	ft_putstr("\t[C]          -> Change the camera (isometric <-> plain).\n");
	ft_putstr("\t[⬆️][⬇️][⬅️][➡️] -> Move the map.\n");
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (argc == 2)
	{
		read_lines(argv[1], fdf);
	}
	else
	{
		usage(argv[0]);
	}
	return (0);
}
