#include "../includes/fdf.h"

void line(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    // *x = x0;
    // *y = y0;
    mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xF32FFF);
    
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

int main(int argc, char **argv)
{
    void **map;

    int i = 40;
    int j = 250;
    int k = 40;
    void *mlx_ptr; 
    void *win_ptr;
    int size_x = P_WIDTH;
    int size_y = P_HEIGHT;
    char *title = "Hellooooo";
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title); // S
    // double vect = sqrt((pow(i, 2)) + (pow(j, 2)));
    // i /= vect;
    // j /= vect;
    
    line(1125, 450, 1500, 600, mlx_ptr, win_ptr);
    line(500, 1000, 1500, 600, mlx_ptr, win_ptr);
    line(500, 1000, 125, 850, mlx_ptr, win_ptr);
    // line(1500, 600, 1000, 400, mlx_ptr, win_ptr);
    // line(125, 850, 11, 1000, mlx_ptr, win_ptr);
    line(125, 850, 1125, 450, mlx_ptr, win_ptr);
    line(1, 1, 1, 1281, mlx_ptr, win_ptr);
    line(1, 1, 721, 1, mlx_ptr, win_ptr);
    line(1, 721, 721, 1281, mlx_ptr, win_ptr);
    // line(500, 1000, 1500, 600, mlx_ptr, win_ptr);
    // line(500, 1000, 1500, 600, mlx_ptr, win_ptr);
    // line(500, 1000, 1500, 600, mlx_ptr, win_ptr);

	// mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xF32FFF);

    // while (i < 1000 && j < 1000)
    // {
	// 	mlx_pixel_put(mlx_ptr, win_ptr, i*0.8, j* 0.8, 0xF32FFF);
	// 	mlx_pixel_put(mlx_ptr, win_ptr, i, k, 0xF32FFF);
    //     i++;
    //     j++;
    //     k++;

    //     // i *= 0.4;
    // }
    
    // mlx_put_image_to_window(mlx_ptr, win_ptr,mlx_new_image (mlx_ptr, 10, 80), 50, 90);
    mlx_loop(mlx_ptr);
    return (0);
}

