/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:21 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/17 13:47:21 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static	void	mix_color(t_fdf *fdf)
{
	fdf->color.R = (rand() % 0x7f);
	fdf->color.G = (rand() % 0x7f);
	fdf->color.B = (rand() % 0x7f);
}

static	void	nomalize_map(t_fdf *fdf)
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
	fdf->color.R = 0x4F;
	fdf->color.G = 0x4F;
	fdf->color.B = 0x4F;
}

static	int	fdf_keys(int keycode, t_fdf *fdf)
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

int		count_values(char *line)
{
	int num_value;
	char **splitted_value;

	num_value = 0;
	splitted_value = ft_strsplit(line, ' ');
	while (*splitted_value)
	{
		num_value++;
		splitted_value++;
	}
	printf("this is my column number here - %d", num_value);
	return (num_value);
}

int	line_count(char *argv, t_fdf *fdf)
{
	int rows;
	int cols;
	int len;
	int fd;
	char *line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Error opening file!", 1);
	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break;
		if (((len = count_values(line)) > cols) && (cols == 0))
			cols = len;
		(cols == len) ? rows += 1 : ft_puterror("Not a valid file!", 4);
		free(line);
	}
	if ((close(fd)) == - 1)
		ft_puterror("Error Closing file!!", 2);
	if (!(fdf->map.length = cols))
		ft_puterror("This is not a valid file", 4);
	return (rows);
}

void	validate_lines(char *line)
{
    while (*line)
	{
		if (ft_isdigit(*line))
		{
			ft_putstr("fine\n"); 
		}
		else if (*line != ' ' && *line != '-')
			ft_puterror("Invalid character read!!\n[Error]", 5);
		line++;
	}
}

static void get_values(t_fdf *fdf, int x, int y, char *line)
{
	int i;
	char **splitted_value;

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

/*
**  Here please note that x ---- length which is the amount on a side
**  while y ---- is the amount of rows we have and this can be called breadth
*/

void		fdf_read(char *argv, t_fdf *fdf)
{
	int fd;
	int x;
	char *line;
	int y;
	
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
		ft_putendl(line);
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
