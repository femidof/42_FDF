#include "./../includes/fdf.h"



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
            // if (fdf->map.breadth > x + 1)
			// 	draw_horizontal(fdf, x, y);
			// if (fdf->map.length > y + 1)
			// 	draw_vertical(fdf, x, y);
			x++;
        }
        y++;
    }
    mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
    return (0);
}