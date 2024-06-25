#include "../include/game.h"

int	mouse = 0;
int	load = 0;

int	exit_prog(t_game *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

void	start_log(t_game *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	data->img_width = 0;
	data->img_height = 0;
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx, "./assets/load.xpm", &data->img_width, &data->img_height);
	if (!data->img.img_ptr)
		exit_prog(data);
	mlx_put_image_to_window (data->mlx, data->win, data->img.img_ptr, 0, 0);
}

void	process_read_next(t_game *data, int *i)
{
	if (*i == -1)
		*i = 1;
	if (*i == 15)
		return ;
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	data->img_width = 0;
	data->img_height = 0;
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx, data->map[*i], &data->img_width, &data->img_height);
	if (!data->img.img_ptr)
		exit_prog(data);
	mlx_put_image_to_window (data->mlx, data->win, data->img.img_ptr, 0, 0);
	(*i)++;
}

void	process_read_prev(t_game *data, int *i)
{
	if (*i == 15)
		*i = 13;
	if (*i == -1)
		return ;
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	data->img_width = 0;
	data->img_height = 0;
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx, data->map[*i], &data->img_width, &data->img_height);
	if (!data->img.img_ptr)
		exit_prog(data);
	mlx_put_image_to_window (data->mlx, data->win, data->img.img_ptr, 0, 0);
	(*i)--;
}

int    check_mouse(int button, int x, int y, t_game *data)
{
	static int	i = 0;

	if (button && mouse == 0)
	{
		if ((x >= 296 && x <= 480) && (y >= 470 && y <= 524))
		{
			load = 1;
			mouse = 1;
			start_log(data);
		}
	}
	else if (button && mouse == 1)
	{
		if ((x >= 1213 && x <= 1258) && (y >= 330 && y <= 392))
			process_read_next(data, &i);
		else if ((x >= 19 && x <= 68) && (y >= 330 && y <= 392))
			process_read_prev(data, &i);
		else if ((x >= 1224 && x <= 1246) && (y >= 13 && y <= 48))
			exit_prog(data);
		else
			return (0);
	}
	return (0);
}


int	key_check(int key, t_game *data)
{
	if (key == ESC)
		exit_prog(data);
	return (0);
}

void init_menu(t_game *data)
{
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx, "./assets/bg.xpm", &data->img.w, &data->img.h);
	if (!data->img.img_ptr)
		exit_prog(data);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			   &data->img.line_len, &data->img.endian);
	mlx_put_image_to_window (data->mlx, data->win, data->img.img_ptr, (data->win_width - data->img.w) / 2, 0);
}

void	init_var(t_game *data)
{
	data->win_width = 1280;
	data->win_height = 720;
	if (!(data->mlx = mlx_init()))
		exit (1);
	if (!(data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Gasikarako")))
		exit (1);
	data->img_width = data->win_width;
	data->img_height = data->win_height;
	data->map[0] = "./assets/1.xpm";
	data->map[1] = "./assets/2.xpm";
	data->map[2] = "./assets/3.xpm";
	data->map[3] = "./assets/4.xpm";
	data->map[4] = "./assets/5.xpm";
	data->map[5] = "./assets/6.xpm";
	data->map[6] = "./assets/7.xpm";
	data->map[7] = "./assets/8.xpm";
	data->map[8] = "./assets/9.xpm";
	data->map[9] = "./assets/10.xpm";
	data->map[10] = "./assets/11.xpm";
	data->map[11] = "./assets/12.xpm";
	data->map[12] = "./assets/13.xpm";
	data->map[13] = "./assets/14.xpm";
	data->map[14] = "./assets/15.xpm";
}

int	main(void)
{
	t_game	data;

	init_var(&data);
	init_menu(&data);
	mlx_mouse_hook(data.win, &check_mouse, &data);
	mlx_hook(data.win, 17, 0, exit_prog, &data);
	mlx_key_hook(data.win, key_check, &data);
	mlx_loop(data.mlx);
}
