#include "../so_long.h"

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
		ft_putstr_fd("ERROR: Unable to read map_file!\n", STDOUT_FILENO);
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

int	check_p(t_map *m)
{
	int	i;
	int	j;
	int	p_num;

	i = 0;
	p_num = 0;
	j = -1;
	while (m->map[++i])
	{
		j = 0;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == 'P')
			{
				p_num++;
				m->player_x = j;
				m->player_y = i;
			}
			if (m->map[i][j] == 'C')
				m->item++;
		}
	}
	if (p_num == 1)
		return (SUCCESS);
	return (FALSE);
}

int	set_map(t_map *map, char *name)
{
	int	i;

	i = 0;
	if (open_map(map, name) == FALSE)
	{
		ft_putstr_fd("ERROR: Unable to read map_file!\n", STDOUT_FILENO);
		exit(1);
	}
	map->item = 0;
	map->move = 0;
	if (check_p(map) == FALSE)
		return (FALSE);
	while (map->map[i])
		i++;
	map->height = i + 1;
	map->width = ft_strlen(map->map[0]) + 1;
	return (SUCCESS);
}
