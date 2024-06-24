/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:34:30 by fidrandr          #+#    #+#             */
/*   Updated: 2024/06/24 14:15:08 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	free_ptr(t_game *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		free(data->mlx);
	}
	exit (1);
}

int    check_mouse(int button, int x, int y, t_pos *pos)
{
	(void)pos;
	if ((x >= 976 && x <= 1004) && (y >= 129 && y <= 147))
		printf("Antsiranana\n");
	else if ((x >= 875 && x <= 907) && (y >= 253 && y <= 271))
		printf("Mahajanga\n");
	else if ((x >= 933 && x <= 984) && (y >= 305 && y <= 321))
		printf("Toamasina\n");
	else if ((x >= 876 && x <= 907) && (y >= 366 && y <= 383))
		printf("Antananarivo\n");
	else if ((x >= 877 && x <= 913) && (y >= 470 && y <= 484))
		printf("Fianarantsoa\n");
	else if ((x >= 807 && x <= 840) && (y >= 585 && y <= 601))
		printf("Toliara\n");
	else
		printf("button = %d et x = %d et y = %d\n", button, x, y);
	return (0);
}

void	begin_program(t_game *game)
{
	game->img_width = 0;
	game->img_height = 0;
	game->img = mlx_xpm_file_to_image(game->mlx, "./assets/Bg.xpm", &game->img_width, &game->img_height);
	if (!game->img)
		return (free_ptr(game));
	mlx_put_image_to_window(game->mlx, game->win, game->img, (game->win_width - game->img_width) / 2, 0);
	mlx_mouse_hook(game->win, &check_mouse, game);
}

void	init_var(t_game *data)
{
	int	i;

	i = -1;
	data->win_width = 1280;
	data->win_height = 720;
	if (!(data->mlx = mlx_init()))
		exit (1);
	if (!(data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "Gasikarako")))
		exit (1);
	data->img_width = data->win_width;
	data->img_height = data->win_height;
	if (!(data->bg_img = mlx_new_image(data->mlx, data->img_width, data->img_height)))
		return (free_ptr(data));
	while (++i < 6)
	{
		data->pos.x[i] = 0;
		data->pos.y[i] = 0;
		data->pos.x1[i] = 0;
		data->pos.y1[i] = 0;
	}
}

int	exit_prog(t_game *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->bg_img)
		mlx_destroy_image(data->mlx, data->bg_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		free(data->mlx);
	}
	exit (0);
}

int	main(void)
{
	t_game	data;

	init_var(&data);
	begin_program(&data);
	mlx_hook(data.win, 17, 0, &exit_prog, &data);
	mlx_loop(data.mlx);
}