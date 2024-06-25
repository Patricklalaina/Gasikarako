#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <unistd.h>

# define ESC 65307

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	void	*bg;
	void	*load_img;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	char	**matrix;
	char	*path;
	int		s_width;
	int		s_height;
	char	*map[15];
}	t_game;


#endif
