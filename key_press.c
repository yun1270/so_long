#include "game.h"

int change_map(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor.img, mlx->player_x * SIZE, mlx->player_y * SIZE);
	mlx->player_x += x;
    mlx->player_y += y;
	if (x == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[3].img, mlx->player_x * SIZE, mlx->player_y * SIZE);
	if (x == -1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[1].img, mlx->player_x * SIZE, mlx->player_y * SIZE);
	if (y == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[0].img, mlx->player_x * SIZE, mlx->player_y * SIZE);
	if (y == -1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[0].img, mlx->player_x * SIZE, mlx->player_y * SIZE);
	return (0);
}

int	check_xy(t_mlx *mlx, int x, int y)
{
    char c;

   c =  mlx->map->map[mlx->player_y + y][mlx->player_x + x];
	if (c == '1')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor.img, mlx->player_x * SIZE, mlx->player_y * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[0].img, mlx->player_x * SIZE, mlx->player_y * SIZE);
		return (FALSE);
	}
	if (c == 'E')
	{
		printf("CLEAR\n");
		change_map(mlx, x, y);
		return (2);
	}
	if (c == 'C')
		mlx->map->item--;
	mlx->map->move++;
	mlx->map->map[mlx->player_y + y][mlx->player_x + x] = 'P';
	mlx->map->map[mlx->player_y][mlx->player_x] = '0';
	change_map(mlx, x, y);
	return (SUCCESS);
}

int key_press(int keycode, t_mlx *mlx)
{
	int  xy;

	if (keycode == KEY_A)
        xy = check_xy(mlx, -1, 0);
	if (keycode == KEY_D)
        xy = check_xy(mlx, 1, 0);
	if (keycode == KEY_S)
        xy = check_xy(mlx, 0, 1);
	if (keycode == KEY_W)
        xy = check_xy(mlx, 0, -1);
	printf("map[%d][%d] = %c\n", mlx->player_y, mlx->player_x, mlx->map->map[mlx->player_y][mlx->player_x]);
	if (keycode == KEY_ESC)
		exit(0);
	if (xy == 2)
    {
		set_map(mlx, "map1.ber");
		make_map(mlx);
		return (1);
    }
    return (SUCCESS);
}
