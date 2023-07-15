/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:45:30 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 10:52:56 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	key_press_hook(int keycode, t_minirt *minirt)
{
	if (minirt == NULL)
		return (1);
	return (keycode);
}

static int	key_release_hook(int keycode, t_minirt *minirt)
{
	if (minirt == NULL)
		return (1);
	if (keycode == ESC_KEY)
		rt_exit(minirt);
	return (keycode);
}

void	rt_event(t_minirt *minirt)
{
	mlx_do_key_autorepeaton(minirt->mlx_struct.init);
	mlx_hook(minirt->mlx_struct.window, KEY_PRESS, 0, \
		key_press_hook, minirt);
	mlx_hook(minirt->mlx_struct.window, KEY_RELEASE, 0, \
		key_release_hook, minirt);
	mlx_hook(minirt->mlx_struct.window, WIN_DESTROY, 0, \
		rt_exit, minirt);
}
