#include <stdlib.h>
#include <mlx.h>

int main(void)
{
	void *mlx;
	void *mlx_win;
	int x = 0;
	int y;

	mlx = mlx_init();
	if (!mlx)
		return (-1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "pouet");

	while ( x < 1000)
	{
		y = 300;
		while ( y < 800)
		mlx_pixel_put(mlx, mlx_win, x, 500, 0xf372d7);
		x++;
	}	
	mlx_loop(mlx);	

	return (0);
}
