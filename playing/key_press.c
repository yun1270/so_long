#include "so_long.h"

int	change_map(t_mlx *mlx, t_map *map, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor.img,
		map->player_x * SIZE, map->player_y * SIZE);
	if (mlx->map->map[map->player_y][map->player_x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit.img,
			map->player_x * SIZE, map->player_y * SIZE);
	else
		mlx->map->map[map->player_y][map->player_x] = '0';
	map->player_x += x;
	map->player_y += y;
	if (x == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[3].img,
			map->player_x * SIZE, map->player_y * SIZE);
	if (x == -1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[1].img,
			map->player_x * SIZE, map->player_y * SIZE);
	if (y == 1 || y == -1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[0].img,
			map->player_x * SIZE, map->player_y * SIZE);
	return (0);
}

int	check_xy(t_mlx *mlx, t_map *map, int x, int y)
{
	char	c;

	c = map->map[map->player_y + y][map->player_x + x];
	if (c == '1')
		return (FALSE);
	if (c == 'E' && (mlx->map->item == 0 || mlx->map->next == NULL))
		return (2);
	if (c == 'C')
	{
		mlx->map->item--;
		if (mlx->map->next != NULL)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->check.img,
				map->item * SIZE, (mlx->map->height - 1) * SIZE);
	}
	mlx->map->move++;
	change_map(mlx, mlx->map, x, y);
	return (SUCCESS);
}

void	change_move(t_mlx *mlx)
{
	int	n;

	n = mlx->map->move;
	if (n <= 999)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->back.img,
			1 * SIZE, (mlx->map->height + 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->back.img,
			2 * SIZE, (mlx->map->height + 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->back.img,
			3 * SIZE, (mlx->map->height + 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[n % 10].img,
			3 * SIZE, (mlx->map->height + 1) * SIZE);
		n /= 10;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[n % 10].img,
			2 * SIZE, (mlx->map->height + 1) * SIZE);
		n /= 10;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[n].img,
			1 * SIZE, (mlx->map->height + 1) * SIZE);
	}
}

int	exit_map(t_mlx *mlx)
{
	mlx->map = mlx->map->next;
	if (mlx->map == NULL)
		exit(1);
	make_map(mlx);
	if (mlx->map->next == NULL)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[5].img,
			0 * SIZE, (mlx->map->height - 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[4].img,
			1 * SIZE, (mlx->map->height - 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[1].img,
			2 * SIZE, (mlx->map->height - 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[7].img,
			3 * SIZE, (mlx->map->height - 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[6].img,
			4 * SIZE, (mlx->map->height - 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[6].img,
			4 * SIZE, (mlx->map->height - 1) * SIZE);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cat[0].img,
			5 * SIZE + (SIZE / 2), (mlx->map->height - 1) * SIZE);
	}
	return (SUCCESS);
}

int	key_press(int keycode, t_mlx *mlx)
{
	int	xy;

	if (keycode == KEY_A)
		xy = check_xy(mlx, mlx->map, -1, 0);
	if (keycode == KEY_D)
		xy = check_xy(mlx, mlx->map, 1, 0);
	if (keycode == KEY_S)
		xy = check_xy(mlx, mlx->map, 0, 1);
	if (keycode == KEY_W)
		xy = check_xy(mlx, mlx->map, 0, -1);
	if (keycode == KEY_ESC)
		exit(0);
	if (xy == SUCCESS && mlx->map->next != NULL)
		change_move(mlx);
	if (mlx->map->item == 0 && mlx->map->next == NULL)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cat[1].img,
			5 * SIZE + (SIZE / 2), (mlx->map->height - 1) * SIZE);
	if (xy == 2)
		exit_map(mlx);
	return (SUCCESS);
}
