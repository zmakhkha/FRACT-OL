/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:26:31 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 15:18:49 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close(keycode, vars);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 5)
	{
		vars -> tr_x = vars -> tr_x + (x * vars ->x_scale);
		vars -> tr_y = vars -> tr_y + (y * vars ->y_scale);
		vars -> x_scale /= 0.5;
		vars -> y_scale /= 0.5;
		vars->m_iter -= 20;
	}
	if (keycode == 4)
	{
		vars -> x_scale *= 0.5;
		vars -> y_scale *= 0.5;
		vars -> tr_x = vars -> tr_x - (x * vars ->x_scale);
		vars -> tr_y = vars -> tr_y - (y * vars ->y_scale);
		vars->m_iter += 20;
	}
	mlx_destroy_image(vars -> mlx, vars -> img.img);
	ft_mandelbrot(&vars);
	return (0);
}
