#include "../so_long.h"

t_img	get_img(char *path, t_mlx *mlx)
{
	t_img	img;
	int		fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd == -1)
	{
		ft_putstr_fd("ERROR: Unable to read img_file!\n", STDOUT_FILENO);
		exit(1);
	}
	img.img = mlx_xpm_file_to_image(mlx->mlx, path, &img.width, &img.height);
	if (img.img == NULL)
	{
		ft_putstr_fd("ERROR: Unable to read img_file!\n", STDOUT_FILENO);
		exit(1);
	}
	return (img);
}

void	set_seoul_img(t_mlx *mlx)
{
	mlx->alpha[0] = get_img("./img/sprite_s.xpm", mlx);
	mlx->alpha[1] = get_img("./img/sprite_e.xpm", mlx);
	mlx->alpha[2] = get_img("./img/sprite_o.xpm", mlx);
	mlx->alpha[3] = get_img("./img/sprite_u.xpm", mlx);
	mlx->alpha[4] = get_img("./img/sprite_l.xpm", mlx);
	mlx->alpha[5] = get_img("./img/sprite_c.xpm", mlx);
	mlx->alpha[6] = get_img("./img/sprite_r.xpm", mlx);
	mlx->alpha[7] = get_img("./img/sprite_a.xpm", mlx);
}

void	set_num_img(t_mlx *mlx)
{
	mlx->num[0] = get_img("./img/sprite_00.xpm", mlx);
	mlx->num[1] = get_img("./img/sprite_01.xpm", mlx);
	mlx->num[2] = get_img("./img/sprite_02.xpm", mlx);
	mlx->num[3] = get_img("./img/sprite_03.xpm", mlx);
	mlx->num[4] = get_img("./img/sprite_04.xpm", mlx);
	mlx->num[5] = get_img("./img/sprite_05.xpm", mlx);
	mlx->num[6] = get_img("./img/sprite_06.xpm", mlx);
	mlx->num[7] = get_img("./img/sprite_07.xpm", mlx);
	mlx->num[8] = get_img("./img/sprite_08.xpm", mlx);
	mlx->num[9] = get_img("./img/sprite_09.xpm", mlx);
}

void	set_img(t_mlx *mlx)
{
	mlx->wall = get_img("./img/wall.xpm", mlx);
	mlx->floor = get_img("./img/floor.xpm", mlx);
	mlx->back = get_img("./img/back.xpm", mlx);
	mlx->exit = get_img("./img/exit.xpm", mlx);
	mlx->check = get_img("./img/check.xpm", mlx);
	mlx->cat[0] = get_img("./img/cat0.xpm", mlx);
	mlx->cat[1] = get_img("./img/cat1.xpm", mlx);
	mlx->player[0] = get_img("./img/standing.xpm", mlx);
	mlx->player[1] = get_img("./img/left1.xpm", mlx);
	mlx->player[2] = get_img("./img/left2.xpm", mlx);
	mlx->player[3] = get_img("./img/right1.xpm", mlx);
	mlx->player[4] = get_img("./img/right2.xpm", mlx);
	mlx->item[0] = get_img("./img/item1.xpm", mlx);
	mlx->item[1] = get_img("./img/item2.xpm", mlx);
	mlx->item[2] = get_img("./img/item3.xpm", mlx);
	set_num_img(mlx);
	set_seoul_img(mlx);
}
