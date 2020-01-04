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
	ft_putstr("\t[M]          -> Colorize this shit!.\n");
	ft_putstr("\t[B][N]       -> Zoom in and zoom out.\n");
	ft_putstr("\t[J][K]       -> Spiky time!\n");
	ft_putstr("\t[Space]      -> Change the camera (isometric <-> plain).\n");
	ft_putstr("\t[W][A][S][D] -> Move the map.\n");
}

int main(int argc, char **argv)
{
    //void **map;
    // My first printed line
    // int i = 40;
    // void *mlx_ptr; 
    // void *win_ptr;
    // int size_x = 500;
    // int size_y = 500;
    // char *title = "Hello";
    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
    // while (i < 250)
    // {
    //     mlx_pixel_put (mlx_ptr, win_ptr, i, 250, 0xFFFFFF);
    //     i++;
    // }
    // // mlx_pixel_put (mlx_ptr, win_ptr, 30, 40, 0xFFFFFF);

    // mlx_loop(mlx_ptr);
    // // return (0);
    
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