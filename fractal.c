/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:18:25 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/29 15:57:06 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		x = tmp;
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
		x = tmp;
		iter++;
	}
	return (iter);
}

int	burning_ship(double x, double y, t_info *info)
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
		y = (-2 * x * y) + b;
		x = tmp;
		iter++;
	}
	return (iter);
}
