#include "../game.h"

int	open_file(char *name)
{
	char	*file;
	int		fd;

	file = ft_strstr(name, ".ber");
	if (ft_strcmp(file, ".ber") != 0)
		return (FALSE);
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR: Unable to read map_file information\n", STDOUT_FILENO);
		exit(1);
	}
	return (fd);
}

int	map_value(char *map, int flag)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map);
	while (flag == 0 && map[i])
		if (map[i++] != '1')
			return (FALSE);
	if (flag != 0 && map[i++] != '1')
		return (FALSE);
	while (flag != 0 && i < len - 1)
	{
		if (map[i] != '1'
			&& map[i] != '0'
			&& map[i] != 'P'
			&& map[i] != 'E'
			&& map[i] != 'C')
			return (FALSE);
		i++;
	}
	if (flag != 0 && map[i] != '1')
		return (FALSE);
	return (SUCCESS);
}

int	open_map(t_map *m, char *name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open_file(name);
	if (fd == FALSE)
		return (FALSE);
	while (get_next_line(fd, &line) > 0)
	{
		if (map_value(line, i) == FALSE)
			return (FALSE);
		m->map[i++] = ft_strjoin(line, "\0");
		free(line);
	}
	if (map_value(line, 0) == FALSE)
		return (FALSE);
	m->map[i++] = ft_strjoin(line, "\0");
	m->map[i] = NULL;
	free(line);
	close(fd);
	m->line = i;
	return (SUCCESS);
}

int	check_p_e(t_map *m, t_mlx *mlx)
{
	int	i;
	int	j;
	int	check[2];

	i = 0;
	j = -1;
	check[0] = 0;
	check[1] = 0;
	m->item = 0;
	m->move = 0;
	while (m->map[++i])
	{
		j = 0;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == 'P')
			{
				check[0]++;
				mlx->player_x = j;
				mlx->player_y = i;
			}
			if (m->map[i][j] == 'E')
				check[1]++;
			if (m->map[i][j] == 'C')
				m->item++;
		}
	}
	if (check[0] == 1 && check[1] == 1)
		return (SUCCESS);
	return (FALSE);
}

int	set_map(t_mlx *mlx, char *name)
{
	name = ft_strjoin("./map/", name);
	if (open_map(mlx->map, name) == FALSE)
	{
		ft_putstr_fd("ERROR: Unable to read map_file information\n", STDOUT_FILENO);
		exit(1);
	}
	if (check_p_e(mlx->map, mlx) == FALSE)
		return (FALSE);
	return (SUCCESS);
}
