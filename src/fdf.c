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
	ft_putstr("\t[C]          -> Color the map!.\n");
	ft_putstr("\t[Z][X]       -> Zoom in and zoom out.\n");
	ft_putstr("\t[J][K]       -> Spiky time!\n");
	ft_putstr("\t[Space]      -> Change the camera (isometric <-> plain).\n");
	ft_putstr("\t[W][A][S][D] -> Move the map.\n");
}

int main(int argc, char **argv)
{
    void **map;

    if (argc == 2)
    {
        /* code */
    }
    else
    {
        usage(argv[0]);
    }
    return (0);
}