#include "../so_long.h"

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
			j++;
		}
		i++;
	}
}

void	set_else(t_mlx *mlx)
{
	int	i;

	i = mlx->map->item;
	if (mlx->map->next != NULL)
	{
		while (--i >= 0)
		{
			put_img(mlx, mlx->item[i % 3].img, i, (mlx->map->height - 1));
		}
		put_img(mlx, mlx->player[3].img, 0, (mlx->map->height + 1));
		put_img(mlx, mlx->num[0].img, 1, (mlx->map->height + 1));
		put_img(mlx, mlx->num[0].img, 2, (mlx->map->height + 1));
		put_img(mlx, mlx->num[0].img, 3, (mlx->map->height + 1));
	}
	if (mlx->width < 9)
		return ;
	put_img(mlx, mlx->num[4].img, (mlx->width - 8), (mlx->height + 2));
	put_img(mlx, mlx->num[2].img, (mlx->width - 7), (mlx->height + 2));
	put_img(mlx, mlx->alpha[0].img, (mlx->width - 6), (mlx->height + 2));
	put_img(mlx, mlx->alpha[1].img, (mlx->width - 5), (mlx->height + 2));
	put_img(mlx, mlx->alpha[2].img, (mlx->width - 4), (mlx->height + 2));
	put_img(mlx, mlx->alpha[3].img, (mlx->width - 3), (mlx->height + 2));
	put_img(mlx, mlx->alpha[4].img, (mlx->width - 2), (mlx->height + 2));
}

int	put_map(t_mlx *mlx, int i, int j, int item_n)
{
	put_img(mlx, mlx->floor.img, j, i);
	if (mlx->map->map[i][j] == '1')
		put_img(mlx, mlx->wall.img, j, i);
	else if (mlx->map->map[i][j] == 'E')
		put_img(mlx, mlx->exit.img, j, i);
	else if (mlx->map->map[i][j] == 'P')
		put_img(mlx, mlx->player[0].img, j, i);
	else if (mlx->map->map[i][j] == 'C')
	{
		--item_n;
		put_img(mlx, mlx->item[item_n % 3].img, j, i);
	}
	return (item_n);
}

int	make_map(t_mlx *mlx)
{
	int	i;
	int	j;
	int	item_n;

	i = -1;
	item_n = mlx->map->item;
	set_mlx(mlx);
	set_else(mlx);
	while (mlx->map->map[++i])
	{
		j = -1;
		while (mlx->map->map[i][++j])
			item_n = put_map(mlx, i, j, item_n);
	}
	return (SUCCESS);
}
