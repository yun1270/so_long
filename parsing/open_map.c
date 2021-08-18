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

int	in_line(t_map *m, char *line, int i, int flag)
{
	if (ft_strcmp(line, "\0") == 0)
	{
		m->map[i] = NULL;
		return (SUCCESS);
	}
	if (map_value(line, flag) == FALSE)
	{
		ft_putstr_fd("ERROR: Value Error in map_file!!\n", STDOUT_FILENO);
		exit(1);
	}
	m->map[i] = ft_strjoin(line, "\0");
	return (1);
}

int	open_map(t_map *m, char *name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open_file(name);
	while (get_next_line(fd, &line) > 0)
	{
		in_line(m, line, i, i);
		i++;
		free(line);
	}
	if (in_line(m, line, i, 0) == 1)
		m->map[++i] = NULL;
	free(line);
	close(fd);
	return (SUCCESS);
}
