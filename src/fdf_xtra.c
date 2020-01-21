/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:04:05 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/20 15:32:58 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void		print_string(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 20, 0xffe43f, "Controls: ");
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 35, 0xffe43f, "[Esc]        -> Exit the program.");
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 50, 0xffe43f, "[E]          -> Color the map!.");
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 65, 0xffe43f, "[Q][A]       -> Zoom in and zoom out.");
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 80, 0xffe43f, "[W][S]       -> Altitude ");
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 95, 0xffe43f, "[C]          -> Change the camera (isometric <-> plain).");
	mlx_string_put(fdf->mlx.init,fdf->mlx.win,20, 110, 0xffe43f, "[^][v][<][➡>] -> Move the map.");
}

void		validate_lines(char *line)
{
	while (*line)
	{
		if ((ft_isdigit(*line)))
		{
			if (ft_strstr(line, ",0x"))
			{
				break;
			}
		}
		else if (*line != ' ' && *line != '-')
			ft_puterror("Invalid character read!!\n[Error]", 5);
		line++;
	}
}

int				count_values(char *line)
{
	int			num_value;
	char		**splitted_value;

	num_value = 0;
	splitted_value = ft_strsplit(line, ' ');
	while (*splitted_value)
	{
		num_value++;
		splitted_value++;
	}
	return (num_value);
}

void drawing_to_display(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	print_string(fdf);
}

int			line_count(char *argv, t_fdf *fdf)
{
	int		rows;
	int		cols;
	int		len;
	int		fd;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Error opening file!", 1);
	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if (((len = count_values(line)) > cols) && (cols == 0))
			cols = len;
		(cols == len) ? rows += 1 : ft_puterror("Not a valid file!", 4);
		free(line);
	}
	if ((close(fd)) == -1)
		ft_puterror("Error Closing file!!", 2);
	if (!(fdf->map.length = cols))
		ft_puterror("This is not a valid file", 4);
	return (rows);
}
