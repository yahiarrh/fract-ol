/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:07:26 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/27 15:17:17 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoomin(double x0, double y0, t_info *info)
{
	info->endx += x0;
	info->starty += y0;
	info->startx += x0;
	info->endy += y0;
	info->endx *= info->scale;
	info->starty *= info->scale;
	info->startx *= info->scale;
	info->endy *= info->scale;
	info->max_iter += 10;
	info->scale_key *= info->scale;
	drawing(info);
}

void	zoomout(double x0, double y0, t_info *info)
{
	info->endx /= info->scale;
	info->starty /= info->scale;
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

int	mouse(int key, int x, int y, t_info *info)
{
	double	x0;
	double	y0;

	x0 = rescale(x, info->endx, info->startx);
	y0 = rescale(y, info->endy, info->starty);
	if (key == 4)
		zoomout(x0, y0, info);
	if (key == 5)
		zoomin(x0, y0, info);
	return (0);
}
