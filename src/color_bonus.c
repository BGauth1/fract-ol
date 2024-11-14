/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:13:41 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/06 18:06:16 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	next_palette(int palette)
{
	palette++;
	if (palette > 3)
		palette = 1;
	return (palette);
}

static int	argb_value(int a, int r, int g, int b)
{
	return ((((a & 0xff) << 24) | (r & 0xff) << 16) | ((g & 0xff) << 8)
		| (b & 0xff));
}

int	color_from_palette(int palette, int iter)
{
	int	color;

	color = 0;
	if (palette == 1)
		color = argb_value(0, iter * 20, 0, 0);
	else if (palette == 2)
		color = argb_value(0, iter * 20, iter * 20, 0);
	else if (palette == 3)
		color = argb_value(0, iter * 20, iter * 20, iter * 20);
	else
		color = argb_value(0, 200 - iter * 2, 200 - iter * 2, 200 - iter * 2);
	return (color);
}
