/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:52:35 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/24 20:03:01 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
# include <stdarg.h>
#define SIZE 500


typedef struct s_info
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	float		x;
	float		y;
	int		max_iter;
	double	endx;
	double	endy;
	double	startx;
	double	starty;
	double	juliax;
	double	juliay;
	double	scale_key;
	double	scale;
	int		fractal;
	int		ms;
} t_info;

int	ft_strcmp(char *s1, char *s2);
int	ft_printf(const char *arg, ...);

#endif