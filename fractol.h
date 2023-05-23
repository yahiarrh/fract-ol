/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:52:35 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:20 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
	float		x;
	float		y;
	int		max_iter;
	double	endx;
	double	endy;
	double	startx;
	double	starty;
	double	scale;
} t_info;


#endif