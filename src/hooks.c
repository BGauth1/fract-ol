/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:13:29 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/06 18:04:47 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (button == 5)
		mlx->zoom *= 1.2;
	else if (button == 4)
		mlx->zoom /= 1.2;
	fractal(*mlx);
	return (0);
}

int	hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		ft_exit(mlx);
	return (0);
}
