#include "so_long.h"

void	put_img(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * SIZE, y * SIZE);
}

int	key_exit(int keycode, int n)
{
	if (keycode == 17)
		exit(n);
	exit(n);
}

int	main(int ac, char *av[])
{
	t_mlx	*mlx;

	if (ac == 1)
	{
		ft_putstr_fd("ERROR: Need map_file!\n", STDOUT_FILENO);
		exit(0);
	}
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	set_img(mlx);
	all_map(mlx, av);
	mlx->win = mlx_new_window(mlx->mlx, SIZE * mlx->width,
			SIZE * (mlx->height + 4), "so_long");
	make_map(mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, key_press, mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, key_exit, 0);
	mlx_loop(mlx->mlx);
	exit(1);
}
