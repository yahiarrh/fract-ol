/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:52:38 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/26 14:49:45 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void    init(t_info *info)
{
	info->startx = -2;
	info->endx = 2;
	info->starty = -2;
	info->endy = 2;
	info->scale_key = 0.2;
	info->scale = 0.5;
	info->max_iter = 100;
	info->color = 50;
	info->ms = 1;
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
	b = 5 * i * (cos(info->color) + 1);
	g = 4 * i * (1 + sin(info->color) + 1);
	r = i * (1 - cos(info->color));
	return ((r << 16 | g << 8 | b));
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
	a = info->juliax;
	b = info->juliay;
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
			if(info->fractal == 1)
				i = mandelbrot(rescale(x, info->endx, info->startx), rescale(y, info->endy, info->starty), info);
			else if(info->fractal == 2)
				i = julia(rescale(x, info->endx, info->startx), rescale(y, info->endy, info->starty), info);
			my_mlx_pixel_put(info,  x, y,  create_trgb(i, info));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0 , 0);
}

int	boom(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img);
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
	return (0);
}

int	keybord(int	key, t_info *info)
{
	if (key == 53)
	{
		boom(info);
	}
	if (key == 123)
	{
		info->endx += info->scale_key;
		info->startx += info->scale_key;
		drawing(info);
	}
	if (key == 124)
	{
		info->endx -= info->scale_key;
		info->startx -= info->scale_key;
		drawing(info);
	}
	if (key == 125)
	{
		info->endy -= info->scale_key;
		info->starty -= info->scale_key;
		drawing(info);
	}
	if (key == 126)
	{
		info->endy += info->scale_key;
		info->starty += info->scale_key;
		drawing(info);
	}
	if (key == 8)
	{
		info->color += 100;
		drawing(info);
	}
	if (key == 35)
	{
		info->color -= 100;
		drawing(info);
	}
	if (key == 1)
		info->ms = -1;
	if (key == 46)
		info->ms = 1;
	if (key == 15)
	{
		info->startx = -2;
		info->endx = 2;
		info->starty = -2;
		info->endy = 2;
		info->scale_key = 0.2;
		drawing(info);
	}
	return (key);
}

int mouse(int key,int x, int y, t_info *info)
{
	double x0;
	double y0;

	x0 = rescale(x, info->endx, info->startx);
	y0 = rescale(y, info->endy, info->starty);
	if (key == 4)
	{
		info->endx /= info->scale;
		info->starty  /= info->scale;
		info->startx /= info->scale;
		info->endy /= info->scale;
		info->endx -= x0;
		info->starty -= y0;
		info->startx -= x0;
		info->endy -= y0;
		info->max_iter -= 10;
		info->scale_key /= info->scale;
		drawing(info);
	}
	if (key == 5)
	{
		info->endx += x0;
		info->starty += y0;
		info->startx += x0;
		info->endy += y0;
		info->endx *= info->scale;
		info->starty  *= info->scale;
		info->startx *= info->scale;
		info->endy *= info->scale;
		info->max_iter += 10;
		info->scale_key *= info->scale;
		drawing(info);
	}
	return (0);
}

int	mouse_moves(int x, int y, t_info *info)
{
	if ( x <= SIZE && y <= SIZE && info->ms == 1)
	{
		info->juliax = rescale(x, info->endx, info->startx);
		info->juliay = rescale(y, info->endy, info->starty);
		drawing(info);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_info info;

	if (ac == 1)
	{
		ft_printf("Please Enter a Fractal\n");
		exit (0);
	}
	if (!ft_strcmp("Mandelbrot", av[1]))
		info.fractal = 1;
	else if (!ft_strcmp("Julia", av[1]))
		info.fractal = 2;
	else
	{		
		ft_printf("Wrong Fractals Name try :\n Mandelbrot | Julia\n");
		exit(1);
	}
	init(&info);
	info.mlx = mlx_init();
	info.mlx_win = mlx_new_window(info.mlx, SIZE, SIZE, "FRACT-OL");
	info.img = mlx_new_image(info.mlx, SIZE, SIZE);
	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
	// mlx_key_hook(info.mlx_win, keybord, &info);
	mlx_mouse_hook(info.mlx_win, mouse, &info);
	mlx_hook(info.mlx_win, 6, 0, mouse_moves, &info);
	mlx_hook(info.mlx_win, 3, 0, keybord, &info);
	mlx_hook(info.mlx_win, 17, 0, boom, &info);
	drawing(&info);
	mlx_loop(info.mlx);
}