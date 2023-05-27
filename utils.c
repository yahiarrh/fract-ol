/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:56:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/27 16:15:29 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;
	int				i;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s11[i] && s22[i] && s11[i] == s22[i])
		i++;
	return (s11[i] - s22[i]);
}

void	init(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, SIZE, SIZE, "FRACT-OL");
	info->img = mlx_new_image(info->mlx, SIZE, SIZE);
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel,
			&info->line_length, &info->endian);
	info->startx = -2;
	info->endx = 2;
	info->starty = -2;
	info->endy = 2;
	info->scale_key = 0.2;
	info->scale = 0.5;
	info->max_iter = 70;
	info->color = 50;
	info->ms = 1;
}

double	rescale(double a, double end, double start)
{
	return (((a / SIZE) * (end - start)) + start);
}

int	boom(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img);
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
	return (0);
}
