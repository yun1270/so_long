#include "../so_long.h"

void	check_e(t_map *m, int i, int j, int num[])
{
	if (m->map[i][j] == 'E')
		num[0]++;
	if (m->map[i][j] == 'P')
	{
		num[1]++;
		m->player_x = j;
		m->player_y = i;
	}
	if (m->map[i][j] == 'C')
		m->item++;
}

int	check_p(t_map *m)
{
	int	i;
	int	j;
	int	num[2];

	i = 0;
	num[0] = 0;
	num[1] = 0;
	j = -1;
	while (m->map[++i])
	{
		j = 0;
		while (m->map[i][++j])
			check_e(m, i, j, num);
	}
	if (num[0] == 1 && num[1] == 1)
		return (SUCCESS);
	return (FALSE);
}

int	set_map(t_map *map, char *name)
{
	int	i;

	i = 0;
	if (open_map(map, name) == FALSE)
	{
		ft_putstr_fd("ERROR: Value Error in map_file!!\n", STDOUT_FILENO);
		exit(1);
	}
	while (map->map[++i])
	{
		if (ft_strlen(map->map[i - 1]) != ft_strlen(map->map[i]))
			return (FALSE);
	}
	map->item = 0;
	map->move = 0;
	if (check_p(map) == FALSE)
		return (FALSE);
	i = 0;
	while (map->map[i])
		i++;
	map->height = i + 1;
	map->width = ft_strlen(map->map[0]) + 1;
	return (SUCCESS);
}
