#include "game.h"

int make_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map->map[i])
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			printf("%c ", mlx->map->map[i][j]);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor.img, j * SIZE, i * SIZE);
			if (mlx->map->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall.img, j * SIZE, i * SIZE);
			else if (mlx->map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit.img, j * SIZE, i * SIZE);
			else if (mlx->map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[0].img, j * SIZE, i * SIZE);
			else if (mlx->map->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item[0].img, j * SIZE, i * SIZE);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}

int main()
{
    char *name = "map.ber";
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->map = malloc(sizeof(t_map));

	// mlx_init 으로 연결
	mlx->mlx = mlx_init();
	// mlx_nex_window로 창 열기
	mlx->win = mlx_new_window(mlx->mlx, 600, 600, "so_long");
	// ======> mlx 초기화


	// map 확인
	// printf("\n%d\n%d %d\n",set_map(m, mlx, "map.ber"), mlx->player_x, mlx->player_y);
	set_map(mlx, name);
	set_img(mlx);
	make_map(mlx);

	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, key_press, mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, exit, 0);
	// mlx_loop_hook(mlx->mlx, make_map, mlx);
	mlx_loop(mlx->mlx);

	exit(1);
}
