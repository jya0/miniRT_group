/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:10:37 by jyao              #+#    #+#             */
/*   Updated: 2023/05/24 15:35:03 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_render(t_minirt	*minirt)
{
	if (minirt == NULL)
		return (1);
	return (0);
}

int	rt_render_mlx_win_init(t_minirt	*minirt)
{
	if (minirt == NULL)
		return (1);
	minirt->mlx_struct.init = mlx_init();
	if (minirt->mlx_struct.init == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	minirt->mlx_struct.window = \
		mlx_new_window(minirt->mlx_struct.init, WIN_SIZE_X, WIN_SIZE_Y, WIN_NAME);
	if (minirt->mlx_struct.window == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	minirt->mlx_struct.img_canvas = \
		mlx_new_image(minirt->mlx_struct.init, WIN_SIZE_X, WIN_SIZE_Y);
	if (minirt->mlx_struct.img_canvas == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	
	return (0);
}