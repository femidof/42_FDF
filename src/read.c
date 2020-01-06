#include "../includes/fdf.h"

int main(int argc, char **argv)
{
    void **map;

    int i = 40;
    void *mlx_ptr; 
    void *win_ptr;
    int size_x = 1080;
    int size_y = 720;
    char *title = "Hello";
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
    // while (i < 250)
    // {
        // mlx_pixel_put (mlx_ptr, win_ptr, i, 250, 0xFFFFFF);
    //     i++;
    // }
    
    mlx_put_image_to_window(mlx_ptr, win_ptr,mlx_new_image (mlx_ptr, 10, 80), 50, 90);
    mlx_loop(mlx_ptr);
    return (0);
}