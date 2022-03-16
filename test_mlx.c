#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>

typedef struct s_setup
{
	void *mlx;
	void *win;
} t_setup;

int key_move(int keycode, t_setup *setup)
{	
	char	*path_char = "./face.xpm";
	//char	*relative_path = "./ground.xpm";
	int		x;
	int		y;
	//int		w = 0;
	//int		h = 0;
	int		w1 = 192;
	int 	h1 = 384;
	//void 	*img = mlx_xpm_file_to_image(setup->mlx, relative_path, &x, &y);
	void 	*img_char = mlx_xpm_file_to_image(setup->mlx, path_char, &x, &y);
	void *nxt_img_char;

	mlx_put_image_to_window(setup->mlx, setup->win, img_char, w1, h1);

		while (keycode == 100 || keycode == 65364)
		{
			h1 += 96;
			mlx_destroy_image(setup->mlx, img_char);
			//mlx_xpm_file_to_image(setup->mlx, "ground.xpm", &w1, &h1);
			nxt_img_char = mlx_xpm_file_to_image(setup->mlx, "./face_left_foot.xpm", &x, &y);
			mlx_put_image_to_window(setup->mlx, setup->win, nxt_img_char, w1, h1);
		}
	return 0;
}

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
	void 	*img_char;
	char	*path_char = "./face.xpm";
	char	*relative_path = "./ground.xpm";
	int		x;
	int		y;
	int		w = 0;
	int		h = 0;
	int		w1 = 192;
	int 	h1 = 384;

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
	img_char = mlx_xpm_file_to_image(setup.mlx, path_char, &x, &y);
	mlx_put_image_to_window(setup.mlx, setup.win, img_char, w1, h1);
	mlx_hook(setup.win, 2, (1L<<0), &key_close, &setup);	
	mlx_hook(setup.win, 17, 0, &mouse_close, (&setup));
	mlx_hook(setup.win, 2, (1L<<0), &key_move, &setup);	
	mlx_loop(setup.mlx);
	mlx_destroy_image(setup.mlx, img);
	mlx_destroy_window(setup.mlx, setup.win);
	mlx_destroy_display(setup.mlx);
	free(setup.mlx);

	return (0);
}