/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:59:41 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/19 17:29:41 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static long double	power_of_dec(char *s)
{
	long double	res;
	int			i;
	int			j;

	res = 1;
	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == '0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] > '0' && s[i] <= '9')
			j = i + 1;
		i++;
	}
	i = 0;
	while (i < j)
	{
		res /= 10;
		i++;
	}
	return (res);
}

static long double	ft_atof(char *s, int *err)
{
	long double	n1;
	long double	n2;
	char		*tmp;
	char		*s2;

	n1 = (long double)ft_atoi(s, err);
	tmp = ft_strrchr(s, '.');
	if (tmp == NULL)
		return (n1);
	s2 = ft_substr(tmp, 1, 6);
	n2 = (long double)ft_atoi(s2, NULL);
	n2 *= power_of_dec(s2);
	free(s2);
	if (n1 < 0)
		n2 *= -1;
	n1 += n2;
	return (n1);
}

long double	ft_atof_alnum(t_mlx *mlx, char *s)
{
	long double	result;
	int			i;
	int			err;

	i = 0;
	err = 0;
	if (s[i] != '+' && s[i] != '-' && !(s[i] >= '0' && s[i] <= '9'))
		ft_exit_msg(mlx, "Unexpected non-numeric parameter. \
Try ./fractol -h\n", 2);
	i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		ft_exit_msg(mlx, "Unexpected non-numeric parameter. \
Try ./fractol -h\n", 2);
	result = ft_atof(s, &err);
	if (err < 0 || result > 2 || result < -2)
		ft_exit_msg(mlx, "Parameter too large/small. \
Try ./fractol -h\n", 2);
	return (result);
}
