/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:13:47 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/19 15:30:30 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "libft/libft.h"

# define WIN_WIDTH	400
# define WIN_HEIGHT	400

# define K_ESC		65307
# define K_UP		65362
# define K_DOWN		65364
# define K_LEFT		65361
# define K_RIGHT	65363
# define K_Z		122
# define K_X		120
# define K_R		114
# define K_C		99

# define M_SCRL_UP	4
# define M_SRCL_DWN	5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fduo
{
	long double	x;
	long double	y;
}				t_fduo;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
	t_fduo		c;
	t_fduo		pos_view;
	long double	zoom;
	int			palette;
	int			frac_type;
	int			nb_iter;
}				t_mlx;

//          COLOR.C         //
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			next_palette(int palette);
int			color_from_palette(int palette, int iter);

//			HOOKS.C			//
int			hook_keydown(int key, t_mlx *mlx);
int			hook_mousedown(int button, int x, int y, t_mlx *mlx);

//			FRACTAL.C		//
void		fractal(t_mlx mlx);
long double	pixel_to_coord(int pixel, int size,
				long double zoom, long double off);

//			PARSING.C		//
int			ft_exit(t_mlx *mlx);
void		ft_exit_msg(t_mlx *mlx, char *msg, int fd);
void		apply_params(t_mlx *mlx, int ac, char **av);

//			FT_ATOF.C		//
long double	ft_atof_alnum(t_mlx *mlx, char *s);

#endif