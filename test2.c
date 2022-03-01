#include <stdlib.h>
#include "mlx.h"

int main (void)
{
	void *mlx;
	void *my_win;	
	int x = 1920;
	int y = 1080;
	int color = 0xFF714D;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	my_win = mlx_new_window(mlx, x, y, "test");
	if (my_win == NULL)
	{
		free(my_win);
		return (1);	
	}
	y  = 300;
	while (y < 900)
	{
			mlx_pixel_put(mlx, my_win, 300, y++, color);
	}
		while (1)
		;
	mlx_destroy_window(mlx, my_win);
	mlx_destroy_display(mlx);
	free(mlx);
}
