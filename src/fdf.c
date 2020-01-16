/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:15:51 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/09 18:15:56 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void mix_color(t_fdf *fdf)
{
    fdf->color.R = (rand() % 0x7f);
    fdf->color.G = (rand() % 0x7f);
    fdf->color.B = (rand() % 0x7f);
}

static int fdf_keys(int keycode, t_fdf *fdf)
{
    if (keycode == KEY_ESCAPE)
        exit(0);
    else if (keycode == KEY_ANSI_R)
        nomalize_map(fdf);
    else if (keycode == KEY_UPARROW)
        fdf->map.coord_y -= 1;
    else if (keycode == KEY_DOWNARROW)
        fdf->map.coord_y += 1;
    else if (keycode == KEY_LEFTARROW)
        fdf->map.coord_x -= 1;
    else if (keycode == KEY_RIGHTARROW)
        fdf->map.coord_x += 1;
    else if (keycode == KEY_ANSI_Q)
        fdf->map.scalin += 1;
    else if ((keycode == KEY_ANSI_A) && fdf->map.scalin < MAX_ZOOM)
        fdf->map.scalin -= 1;
    else if (keycode == KEY_ANSI_W)
        fdf->map.z_value += 0.25;
    else if (keycode == KEY_ANSI_S)
        fdf->map.z_value -= 0.25;
    else if (keycode == KEY_ANSI_C)
        fdf->map.angle_y *= (fdf->map.isometric++ % 2) ? 0.2 : 5;
    else if (keycode == KEY_ANSI_E)
        mix_color(fdf);
//     else if (keycode ==)
// ;        /* code */;
//     else if (keycode ==)
// ;        /* code */;
//     else if (keycode ==)
// ;        /* code */;
//     else if (keycode ==)
//         /* code */;
    return (0);
        
}

/*
**  Shows how to run and use fdf
*/
void usage(char *argv0)
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

int main(int argc, char **argv)
{
    // void **map;
    t_fdf *fdf;

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
