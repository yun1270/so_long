#include "../game.h"

t_img	get_img(char *path, t_mlx *mlx)
{
	t_img img;
	int fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd == -1)
	{
		ft_putstr_fd("ERROR: Unable to read img_file information\n", STDOUT_FILENO);
		exit(1);
	}
	img.img = mlx_xpm_file_to_image(mlx->mlx, path, &img.width, &img.height);
	if (img.img == NULL)
	{
		ft_putstr_fd("ERROR: Unable to read img_file information\n", STDOUT_FILENO);
		exit(1);
	}
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}

void	set_img(t_mlx *mlx)
{
	mlx->wall = get_img("./img/wall.xpm", mlx);
	mlx->floor = get_img("./img/floor.xpm", mlx);
	mlx->exit = get_img("./img/exit.xpm", mlx);
	mlx->player[0] = get_img("./img/standing.xpm", mlx);
	mlx->player[1] = get_img("./img/left1.xpm", mlx);
	mlx->player[2] = get_img("./img/left2.xpm", mlx);
	mlx->player[3] = get_img("./img/right1.xpm", mlx);
	mlx->player[4] = get_img("./img/right2.xpm", mlx);
	mlx->item[1] = get_img("./img/item1.xpm", mlx);
	mlx->item[2] = get_img("./img/item2.xpm", mlx);
	mlx->item[0] = get_img("./img/item3.xpm", mlx);
}
