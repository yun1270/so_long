#include "../so_long.h"

void	check_end_val(t_mlx *mlx, int i, int j, int fd)
{
	if ((i == 0 || i == mlx->height - 1)
		|| (j == 0 || j == mlx->width - 2))
		ft_putchar_fd('1', fd);
	else if (i == 1 && j == 1)
		ft_putchar_fd('P', fd);
	else if (i == mlx->height - 2 && j == mlx->width - 3)
		ft_putchar_fd('E', fd);
	else if (i == mlx->height / 2)
		ft_putchar_fd('C', fd);
	else
		ft_putchar_fd('0', fd);
}

void	make_end_map(t_mlx *mlx)
{
	int	fd;
	int	i;
	int	j;

	fd = open("./map/end.ber", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == FALSE)
	{
		ft_putstr_fd("ERROR: Unable to make end_file!\n", STDOUT_FILENO);
		exit(1);
	}
	i = -1;
	while (++i < mlx->height)
	{
		j = -1;
		while (++j < mlx->width - 1)
			check_end_val(mlx, i, j, fd);
		ft_putchar_fd('\n', fd);
	}
}

void	push_map(t_mlx *mlx, char *name)
{
	t_map	*tmp;
	t_map	*m;

	m = malloc(sizeof(t_map));
	name = ft_strjoin("./map/", name);
	if (set_map(m, name) == FALSE)
	{
		ft_putstr_fd("ERROR: Value Error in map_file!!!\n", STDOUT_FILENO);
		exit(1);
	}
	m->next = NULL;
	tmp = mlx->map;
	if (tmp == NULL)
		mlx->map = m;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = m;
	}
}

int	all_map(t_mlx *mlx)
{
	t_map	*tmp;

	mlx->map = NULL;
	push_map(mlx, "map0.ber");
	push_map(mlx, "map1.ber");
	push_map(mlx, "map2.ber");
	tmp = mlx->map;
	mlx->width = tmp->width;
	mlx->height = tmp->height;
	while (tmp->next)
	{
		if (tmp->height < tmp->next->height)
			mlx->height = tmp->next->height;
		if (tmp->width < tmp->next->width)
			mlx->width = tmp->next->width;
		tmp = tmp->next;
	}
	make_end_map(mlx);
	push_map(mlx, "end.ber");
	return (SUCCESS);
}
