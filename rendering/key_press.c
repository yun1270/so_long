#include "../so_long.h"

int	change_map(t_mlx *mlx, t_map *map, int x, int y)
{
	put_img(mlx, mlx->floor.img, map->player_x, map->player_y);
	if (mlx->map->map[map->player_y][map->player_x] == 'E')
		put_img(mlx, mlx->exit.img, map->player_x, map->player_y);
	else
		mlx->map->map[map->player_y][map->player_x] = '0';
	map->player_x += x;
	map->player_y += y;
	if (x == 1)
		put_img(mlx, mlx->player[3].img, map->player_x, map->player_y);
	if (x == -1)
		put_img(mlx, mlx->player[1].img, map->player_x, map->player_y);
	if (y == 1 || y == -1)
		put_img(mlx, mlx->player[0].img, map->player_x, map->player_y);
	return (SUCCESS);
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
			put_img(mlx, mlx->check.img, map->item, mlx->map->height - 1);
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
		put_img(mlx, mlx->back.img, 1, (mlx->map->height + 1));
		put_img(mlx, mlx->back.img, 2, (mlx->map->height + 1));
		put_img(mlx, mlx->back.img, 3, (mlx->map->height + 1));
		put_img(mlx, mlx->num[n % 10].img, 3, (mlx->map->height + 1));
		n /= 10;
		put_img(mlx, mlx->num[n % 10].img, 2, (mlx->map->height + 1));
		n /= 10;
		put_img(mlx, mlx->num[n].img, 1, (mlx->map->height + 1));
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
		put_img(mlx, mlx->alpha[5].img, 0, (mlx->height + 2));
		put_img(mlx, mlx->alpha[4].img, 1, (mlx->height + 2));
		put_img(mlx, mlx->alpha[1].img, 2, (mlx->height + 2));
		put_img(mlx, mlx->alpha[7].img, 3, (mlx->height + 2));
		put_img(mlx, mlx->alpha[6].img, 4, (mlx->height + 2));
		put_img(mlx, mlx->cat[0].img, 4, (mlx->height + 1));
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
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit(0);
	if (xy == SUCCESS && mlx->map->next != NULL)
		change_move(mlx);
	if (mlx->map->item == 0 && mlx->map->next == NULL)
		put_img(mlx, mlx->cat[1].img, 4, (mlx->height + 1));
	if (xy == 2)
		exit_map(mlx);
	return (SUCCESS);
}
