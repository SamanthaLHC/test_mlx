#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>


typedef struct s_setup
{
	void *mlx;
	void *my_win;
}	t_setup;


//pour supprimer uniquement avc escp
int key_close(int keycode, t_setup *setup)
{
	if (keycode == 65307)
		mlx_loop_end(setup->mlx);
	return(0);
}

/*
int mouse_close(int button , int x, int y, t_setup *setup)
{
	(void)x;
	(void)y;

	if (button == 1)
		mlx_loop_end(setup->mlx);
	return (0);
}
*/

//(pour destroy notify?? do not work)
int mouse_close (t_setup *setup)
{
	mlx_loop_end(setup->mlx);
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

	/*
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
	*/
	mlx_hook(setup.my_win, 2, (1L<<0), &key_close, &setup);	
	mlx_hook(setup.my_win, 17, 0, &mouse_close, (&setup));
	//mlx_mouse_hook(setup.my_win, &mouse_close, &setup);
	mlx_loop(setup.mlx);
	mlx_destroy_window(setup.mlx, setup.my_win);
	mlx_destroy_display(setup.mlx);
	free(setup.mlx);

	return (0);
}
