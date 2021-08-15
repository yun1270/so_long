#ifndef GAME_H
# define GAME_H

/*include*/
#include "./mlx/mlx.h"
#include "./libft/libft.h"
// #include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 10
# define OPEN_MAX 32

#define SIZE 16

#define FALSE 1
#define SUCCESS 0
#define ERROR -1

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct		s_map
{
	char			*map[256];
	int				line;
	int				item;
	int				move;
}					t_map;

typedef struct		s_img
{
	void			*img;
	int				width;
	int				height;
	int				*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

/* mlx 창에 대한 정보 */
typedef struct	s_mlx
{
	void		*mlx;	// 연결 식별자
	void		*win;	//지정된 창
	int			player_x;
	int			player_y;
	t_map		*map;
	t_img		wall;
	t_img		floor;
	t_img		exit;
	t_img		player[5];
	t_img		item[3];
}				t_mlx;



void	set_img(t_mlx *mlx);
int		get_next_line(int fd, char **line);
int		set_map(t_mlx *mlx, char *name);
int		key_press(int keycode, t_mlx *mlx);
int		make_map(t_mlx *mlx);

#endif
