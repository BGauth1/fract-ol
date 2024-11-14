/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:13:34 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/19 17:41:24 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.width = WIN_WIDTH;
	mlx.height = WIN_HEIGHT;
	if (ac < 2)
		ft_exit_msg(&mlx, "No parameter used. Try ./fractol -h\n", 2);
	apply_params(&mlx, ac, av);
	mlx.palette = 1;
	mlx.pos_view.x = 0;
	mlx.pos_view.y = 0;
	mlx.zoom = 1;
	mlx.nb_iter = 50;
	mlx.win = mlx_new_window(mlx.ptr, mlx.width, mlx.height, "Fractol");
	fractal(mlx);
	mlx_key_hook(mlx.win, hook_keydown, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, hook_mousedown, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_exit, &mlx);
	mlx_loop(mlx.ptr);
}
