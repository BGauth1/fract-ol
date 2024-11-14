/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:13:38 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/06 18:10:13 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

long double	pixel_to_coord(int pixel, int size,
						long double zoom)
{
	return ((((4 * (long double)pixel - 2 * size) / size) * zoom));
}

int	julia_color(int x, int y, t_mlx mlx)
{
	t_fduo	z;
	t_fduo	tmpz;
	int		j;

	z.x = pixel_to_coord(x, mlx.width, mlx.zoom);
	z.y = -pixel_to_coord(y, mlx.height, mlx.zoom);
	j = 0;
	while (z.x * z.x + z.y * z.y < 4 && j < 60)
	{
		tmpz.x = z.x * z.x - z.y * z.y + mlx.c.x;
		tmpz.y = z.x * z.y * 2 + mlx.c.y;
		if (z.x == tmpz.x && z.y == tmpz.y)
			j = 59;
		z.x = tmpz.x;
		z.y = tmpz.y;
		j++;
	}
	if (j == 60)
		return (0);
	return (argb_value(0, j * 20, 0, 0));
}

int	mandelbrot_color(int x, int y, t_mlx mlx)
{
	t_fduo	z;
	t_fduo	tmpz;
	int		j;

	z.x = 0;
	z.y = 0;
	mlx.c.x = pixel_to_coord(x, mlx.width, mlx.zoom);
	mlx.c.y = -pixel_to_coord(y, mlx.height, mlx.zoom);
	j = 0;
	while (z.x * z.x + z.y * z.y < 4 && j < 60)
	{
		tmpz.x = z.x * z.x - z.y * z.y + mlx.c.x;
		tmpz.y = z.x * z.y * 2 + mlx.c.y;
		if (z.x == tmpz.x && z.y == tmpz.y)
			j = 59;
		z.x = tmpz.x;
		z.y = tmpz.y;
		j++;
	}
	if (j == 60)
		return (0);
	return (argb_value(0, j * 20, 0, 0));
}

void	fractal(t_mlx mlx)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(mlx.ptr, mlx.width, mlx.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	x = 0;
	while (x < mlx.width)
	{
		y = 0;
		while (y < mlx.height)
		{
			if (mlx.frac_type == 1)
				my_mlx_pixel_put(&img, x, y, mandelbrot_color(x, y, mlx));
			else if (mlx.frac_type == 2)
				my_mlx_pixel_put(&img, x, y, julia_color(x, y, mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_destroy_image(mlx.ptr, img.img);
}
