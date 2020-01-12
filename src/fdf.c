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
/*
**  Shows how to run and use fdf
*/
void usage(char *argv0)
{
    ft_putstr("\033[0;31mError:\033[0mInvalid file input \n");
    ft_putstr("Usage:\n\t");
	ft_putstr(ft_program_name(argv0));
	ft_putstr(" fdf_file\n");
	ft_putstr("Controls:\n");
	ft_putstr("\t[Esc]        -> Exit the program.\n");
	ft_putstr("\t[R]          -> Reset the map.\n");
	ft_putstr("\t[E]          -> Color the map!.\n");
	ft_putstr("\t[Q][A]       -> Zoom in and zoom out.\n");
	ft_putstr("\t[W][S]       -> Altitude \n");
	ft_putstr("\t[C]          -> Change the camera (isometric <-> plain).\n");
	ft_putstr("\t[⬆][⬇][⬅][➡️] -> Move the map.\n");
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
