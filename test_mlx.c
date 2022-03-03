#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>


typedef struct s_setup
{
	void *mlx;
	void *my_win;
}	t_setup;

int key_close(int keycode, t_setup *setup)
{
	(void)setup;
	printf("%d\n", keycode);
	//mlx_loop_end(setup->mlx);
	return(0);
}

int main(void)
{
	t_setup setup;
	int x = 100;
	int y;

	setup.mlx = mlx_init();
	if (!setup.mlx)
		return (-1);
	setup.my_win = mlx_new_window(setup.mlx, 1920, 1080, "pouet");

	while ( x < 1000)
	{
		y = 300;
		while ( y < 800)
		{
		mlx_pixel_put(setup.mlx, setup.my_win, x, y, 0xf372d7);
		y++;
		}
		x++;
	}
	//mlx_key_hook permet de simmplifier l evenement pour keyup
	mlx_hook(setup.my_win, 2, (1L<<0), &key_close, &setup);	

	mlx_loop(setup.mlx);
	//la boucle tente de recuperer le ptr de la window mm si elle est supprimee donc segfault
	//il faut supprimet apres la loop_end et la loop
	mlx_destroy_window(setup.mlx, setup.my_win);
	mlx_destroy_display(setup.mlx);
	free(setup.mlx);

	return (0);
}
