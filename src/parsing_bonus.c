/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:02:36 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/19 17:46:01 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(1);
}

void	ft_exit_msg(t_mlx *mlx, char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(1);
}

int	get_frac_type(t_mlx *mlx, int ac, char **av)
{
	if (!ft_strncmp("mandelbrot", av[1], 11))
	{
		mlx->frac_type = 1;
		return (2);
	}
	if (!ft_strncmp("burningship", av[1], 12))
	{
		mlx->frac_type = 3;
		return (2);
	}
	else if (!ft_strncmp("julia", av[1], 6))
	{
		if (ac < 4)
			ft_exit_msg(mlx, "Invalid parameter for julia. \
Try ./fractol -h\n", 2);
		mlx->frac_type = 2;
		mlx->c.x = ft_atof_alnum(mlx, av[2]);
		mlx->c.y = ft_atof_alnum(mlx, av[3]);
		return (4);
	}
	else if (!ft_strncmp("-h", av[1], 3) || !ft_strncmp("-help", av[1], 6))
		ft_exit_msg(mlx, "The first parameter must be the model (e.g: \
mandelbrot, julia)\nWith julia, you need to give 2 float values between \
-2.0 and 2.0 (e.g: ./fractol julia -0.3 0.45)\nAfter that you can specify \
the window size with the width and height parameters (e.g: ./fractol \
mandelbrot width=500 height=300)\n\nMove the camera with the arrows, zoom \
using the mouse wheel reset camera with R, change the color palette with C \
and quit using ESC. \n", 1);
	ft_exit_msg(mlx, "Invalid parameter. Try ./fractol -h\n", 2);
	return (0);
}

void	apply_params(t_mlx *mlx, int ac, char **av)
{
	int	i;
	int	err;

	err = 0;
	i = get_frac_type(mlx, ac, av) - 1;
	while (++i < ac)
	{
		if (!ft_strncmp("width=", av[i], 6))
		{
			while (*av[i] != '=')
				av[i]++;
			mlx->width = ft_atoi(++av[i], &err);
		}
		else if (!ft_strncmp("height=", av[i], 7))
		{
			while (*av[i] != '=')
				av[i]++;
			mlx->height = ft_atoi(++av[i], &err);
		}
		else
			ft_exit_msg(mlx, "Invalid parameter. Try ./fractol -h\n", 2);
	}
	if (mlx->height < 10 || mlx->width < 10 || mlx->height > 1500
		|| mlx->width > 1500 || err < 0)
		ft_exit_msg(mlx, "Invalid window size. Try ./fractol -h\n", 2);
}
