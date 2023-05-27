/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:52:38 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/27 16:22:36 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_moves(int x, int y, t_info *info)
{
	if (x <= SIZE && y <= SIZE && x >= 0 && y >= 0 && info->ms == 1)
	{
		info->juliax = rescale(x, info->endx, info->startx);
		info->juliay = rescale(y, info->endy, info->starty);
		drawing(info);
	}
	return (0);
}

void	which_frac(t_info *info, char *av)
{
	if (!ft_strcmp("Mandelbrot", av))
		info->fractal = 1;
	else if (!ft_strcmp("Julia", av))
		info->fractal = 2;
	else if (!ft_strcmp("Tricorn", av))
		info->fractal = 3;
	else
	{		
		ft_printf("Wrong Fractals Name try :\n");
		ft_printf("Mandelbrot | Julia | Tricorn\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 2)
	{
		which_frac(&info, av[1]);
		init(&info);
		drawing(&info);
		mlx_mouse_hook(info.mlx_win, mouse, &info);
		mlx_hook(info.mlx_win, 6, 0, mouse_moves, &info);
		mlx_hook(info.mlx_win, 2, 0, keybord, &info);
		mlx_hook(info.mlx_win, 17, 0, boom, &info);
		mlx_loop(info.mlx);
	}
	else if (ac == 1)
		ft_printf("Please Enter a Fractal\n");
	else
		ft_printf("Wrong Args : [./fractol] [Fractal Name]\n");
}
