#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>

typedef struct s_setup
{
	void *mlx;
	void *win;
} t_setup;

int key_close(int keycode, t_setup *setup)
{
	if (keycode == 65307)
		mlx_loop_end(setup->mlx);
	return(0);
}

int mouse_close (t_setup *setup)
{
	mlx_loop_end(setup->mlx);
	return(0);
}

int main()
{
	t_setup setup;
	void 	*img;
	char	*relative_path = "./parquet_96_2.xpm";
	int		x;
	int		y;
	int		w = 0;
	int		h = 0;

	setup.mlx = mlx_init();
	if (!setup.mlx)
		return (-1);
	setup.win = mlx_new_window(setup.mlx, 1536, 960, "thanks for all the fish, music band");
	img = mlx_xpm_file_to_image(setup.mlx, relative_path, &x, &y);
	while (w <= 1536)
	{
		while (h <= 960)
		{
			mlx_put_image_to_window(setup.mlx, setup.win, img, w, h);
			h+=96;
		}
		h = 0;
		w+=96;
	}
	mlx_hook(setup.win, 2, (1L<<0), &key_close, &setup);	
	mlx_hook(setup.win, 17, 0, &mouse_close, (&setup));
	mlx_loop(setup.mlx);
	mlx_destroy_image(setup.mlx, img);
	mlx_destroy_window(setup.mlx, setup.win);
	mlx_destroy_display(setup.mlx);
	free(setup.mlx);

	return (0);
}