#include <stdlib.h>
#include "mlx.h"

int main (void)
{
	void *mlx;
	void *mlx_win;
	int x = 600;
	int y = 300;


	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	my_win = mlx_new_window(mlx, x, y, "test");
	if (my_win == NULL)
	{
		free(my_win);
		return (1);	
	}
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}
