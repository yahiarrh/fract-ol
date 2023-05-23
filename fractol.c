/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:52:38 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/23 19:40:07 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init(t_info *info)
{
	info->endy = 2;
	info->startx = -2;
	info->endx = 2;
	info->starty = -2;
	info->scale = 0.2;
	info->max_iter = 100;
}

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	rescale(double a, double end, double start)
{
	return (((a / SIZE) * (end - start)) + start);
}

int	create_trgb(int i, t_info *info)
{
	int	r;
	int	g;
	int	b;

	if (i >= info->max_iter)
		return (0);
	b = 5 * i * (cos(4) + 1);
	g = 4 * i * (1 + sin(4) + 1);
	r = i * (1 - cos(4));
	return (r << 16 | g << 8 | b);
}

int	mandelbrot(double x, double y, t_info *info)
{
	double	tmp;
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = x;
	b = y;
	while ((x * x) + (y * y) <= 4 && iter < info->max_iter)
	{
		tmp = ((x * x) - (y * y)) + a;
		y = (2 * x * y) + b;
		x  = tmp;
		iter++;
	}
	return (iter);
}

int	julia(double x, double y, t_info *info)
{
	double	tmp;
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = 0.285;
	b = -0.70176;
	while ((x * x) + (y * y) <= 4 && iter < info->max_iter)
	{
		tmp = ((x * x) - (y * y)) + b;
		y = (2 * x * y) + a;
		x  = tmp;
		iter++;
	}
	return (iter);
}

void	drawing(t_info *info)
{
	int x;
	int y;
	int i;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			i = julia(rescale(x, info->endx, info->startx), rescale(y, info->endy, info->starty), info);
			my_mlx_pixel_put(info,  x, y,  create_trgb(i, info));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0 , 0);
}

int	keybord(int	key, t_info *info)
{
	if (key == 53)
	{
		mlx_destroy_image(info->mlx, info->img);
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit(0);
	}
	if (key == 123)
	{
		info->endx += info->scale;
		info->startx += info->scale;
		drawing(info);
	}
	if (key == 124)
	{
		info->endx -= info->scale;
		info->startx -= info->scale;
		drawing(info);
	}
	if (key == 125)
	{
		info->endy -= info->scale;
		info->starty -= info->scale;
		drawing(info);
	}
	if (key == 126)
	{
		info->endy += info->scale;
		info->starty += info->scale;
		drawing(info);
	}
	return (key);
}

int mouse(int key, t_info *info)
{
	if (key == 4)
	{
		(void)info;
	}
	return (key);
}

int main(int ac, char **av)
{
	t_info info;

	if (ac == 1)
		return (0);
	(void)av;
	init(&info);
	info.mlx = mlx_init();
	info.mlx_win = mlx_new_window(info.mlx, SIZE, SIZE, "FRACT-OL");
	info.img = mlx_new_image(info.mlx, SIZE, SIZE);
	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
	drawing(&info);
	mlx_key_hook(info.mlx_win, keybord, &info);
	mlx_mouse_hook(info.mlx_win, mouse, &info);
	mlx_loop(info.mlx);
}