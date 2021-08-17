#include "so_long.h"\

void	put_img(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * SIZE, y * SIZE);
}

void	set_mlx(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (i < mlx->width)
	{
		j = -1;
		while (j < mlx->height + 4)
		{
			put_img(mlx, mlx->back.img, i, j);
			// mlx_put_image_to_window(mlx->mlx, mlx->win,
			// 	mlx->back.img, i * SIZE, j * SIZE);
			j++;
		}
		i++;
	}
}

void	set_else(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->item)
	{
		put_img(mlx, mlx->item[0].img, i, (mlx->map->height - 1));
		// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item[0].img,
		// 	i * SIZE, (mlx->map->height - 1) * SIZE);
		i++;
	}
	put_img(mlx, mlx->player[3].img, 0, (mlx->map->height + 1));
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player[3].img,
	// 	0, (mlx->map->height + 1) * SIZE);
	put_img(mlx, mlx->num[0].img, 1, (mlx->map->height + 1));
	put_img(mlx, mlx->num[0].img, 2, (mlx->map->height + 1));
	put_img(mlx, mlx->num[0].img, 3, (mlx->map->height + 1));
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[0].img,
	// 	1 * SIZE, (mlx->map->height + 1) * SIZE);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[0].img,
	// 	2 * SIZE, (mlx->map->height + 1) * SIZE);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[0].img,
	// 	3 * SIZE, (mlx->map->height + 1) * SIZE);
}

void	put_42seoul(t_mlx *mlx)
{
	if (mlx->width < 9)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[4].img,
		(mlx->width - 8) * SIZE, (mlx->height + 2) * SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->num[2].img,
		(mlx->width - 7) * SIZE, (mlx->height + 2) * SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[0].img,
		(mlx->width - 6) * SIZE, (mlx->height + 2) * SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[1].img,
		(mlx->width - 5) * SIZE, (mlx->height + 2) * SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[2].img,
		(mlx->width - 4) * SIZE, (mlx->height + 2) * SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[3].img,
		(mlx->width - 3) * SIZE, (mlx->height + 2) * SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[4].img,
		(mlx->width - 2) * SIZE, (mlx->height + 2) * SIZE);
}

void	put_map(t_mlx *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->floor.img, j * SIZE, i * SIZE);
	if (mlx->map->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->wall.img, j * SIZE, i * SIZE);
	else if (mlx->map->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->exit.img, j * SIZE, i * SIZE);
	else if (mlx->map->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->player[0].img, j * SIZE, i * SIZE);
	else if (mlx->map->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->item[0].img, j * SIZE, i * SIZE);
}

int	make_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	set_mlx(mlx);
	if (mlx->map->next != NULL)
		set_else(mlx);
	put_42seoul(mlx);
	while (mlx->map->map[++i])
	{
		j = -1;
		while (mlx->map->map[i][++j])
			put_map(mlx, i, j);
	}
	return (0);
}
