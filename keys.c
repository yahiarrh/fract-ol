/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:55:50 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/27 15:03:35 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	arrows(int key, t_info *info)
{
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
}

static void	couleur(int key, t_info *info)
{
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
}

int	keybord(int key, t_info *info)
{
	if (key == 53)
		boom(info);
	arrows(key, info);
	couleur(key, info);
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
