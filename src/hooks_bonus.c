/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:13:29 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/06 18:41:24 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	t_fduo	tmp_pos;

	if (button == 5)
	{
		tmp_pos.x = pixel_to_coord(x, mlx->width, mlx->zoom, mlx->pos_view.x);
		tmp_pos.y = pixel_to_coord(y, mlx->width, mlx->zoom, mlx->pos_view.y);
		mlx->zoom *= 1.2;
		mlx->pos_view.x += tmp_pos.x - pixel_to_coord(x, mlx->width,
				mlx->zoom, mlx->pos_view.x);
		mlx->pos_view.y += tmp_pos.y - pixel_to_coord(y, mlx->width,
				mlx->zoom, mlx->pos_view.y);
	}
	else if (button == 4)
	{
		tmp_pos.x = pixel_to_coord(x, mlx->width, mlx->zoom, mlx->pos_view.x);
		tmp_pos.y = pixel_to_coord(y, mlx->width, mlx->zoom, mlx->pos_view.y);
		mlx->zoom /= 1.2;
		mlx->pos_view.x += tmp_pos.x - pixel_to_coord(x, mlx->width,
				mlx->zoom, mlx->pos_view.x);
		mlx->pos_view.y += tmp_pos.y - pixel_to_coord(y, mlx->width,
				mlx->zoom, mlx->pos_view.y);
	}
	fractal(*mlx);
	return (0);
}

int	hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		ft_exit(mlx);
	else if (key == K_UP)
		mlx->pos_view.y -= 0.25 * mlx->zoom;
	else if (key == K_DOWN)
		mlx->pos_view.y += 0.25 * mlx->zoom;
	else if (key == K_LEFT)
		mlx->pos_view.x -= 0.25 * mlx->zoom;
	else if (key == K_RIGHT)
		mlx->pos_view.x += 0.25 * mlx->zoom;
	else if (key == K_R)
	{
		mlx->pos_view.x = 0;
		mlx->pos_view.y = 0;
		mlx->zoom = 1;
	}
	else if (key == K_C)
		mlx->palette = next_palette(mlx->palette);
	else if (key == K_Z)
		mlx->nb_iter++;
	else if (key == K_X)
		mlx->nb_iter--;
	fractal(*mlx);
	return (0);
}
