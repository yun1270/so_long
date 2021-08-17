#include "so_long.h"

int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	set_img(mlx);
	all_map(mlx);
	mlx->win = mlx_new_window(mlx->mlx, SIZE * mlx->width,
			SIZE * (mlx->height + 4), "so_long");
	make_map(mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, key_press, mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, exit, 0);
	mlx_loop(mlx->mlx);
	exit(1);
}
