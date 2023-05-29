/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:20:10 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/28 19:33:17 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int i, t_info *info)
{
	int	r;
	int	g;
	int	b;

	if (i == info->max_iter)
		return (0);
	b = 8 * i * (1 + cos(info->color));
	g = 10 * i * (1 + sin(info->color) + 1);
	r = i * (1 - cos(info->color));
	return ((r << 16 | g << 8 | b));
}

void	drawing(t_info *info)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			if (info->fractal == 1)
				i = mandelbrot(rescale(x, info->endx, info->startx),
						rescale(y, info->endy, info->starty), info);
			else if (info->fractal == 2)
				i = julia(rescale(x, info->endx, info->startx),
						rescale(y, info->endy, info->starty), info);
			else if (info->fractal == 3)
				i = burning_ship(rescale(x, info->endx, info->startx),
						rescale(y, info->endy, info->starty), info);
			my_mlx_pixel_put(info, x, y, create_trgb(i, info));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
}
