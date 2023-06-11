/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:38:59 by jyao              #+#    #+#             */
/*   Updated: 2023/06/09 09:23:21 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_color_make(double t, double r, double g, double b)
{
	return (rt_tuple_make(t, r, g, b));
}

static double	clamp(double el_val)
{
	return (el_val * \
		(rt_float_bigger_equal(el_val, 0) \
			&& rt_float_smaller_equal(el_val, 1)) \
			+ 0 * !rt_float_bigger_equal(el_val, 0) \
			+ 1 * !rt_float_smaller_equal(el_val, 1));
}

t_tuple	rt_color_clamp(t_tuple color)
{
	color.x = clamp(color.x);
	color.y = clamp(color.y);
	color.z = clamp(color.z);
	color.w = clamp(color.w);
	return (color);
}

t_tuple	rt_trgb_to_color(int *trgb)
{
	t_tuple	color;

	color.x = (float)(trgb[TRSPT] / TRGB_MAX);
	color.y = (float)(trgb[RED] / TRGB_MAX);
	color.z = (float)(trgb[GREEN] / TRGB_MAX);
	color.w = (float)(trgb[BLUE] / TRGB_MAX);
	return (color);
}

int	rt_color_to_trgb(t_tuple color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = roundf(color.x * TRGB_MAX);
	r = roundf(color.y * TRGB_MAX);
	g = roundf(color.z * TRGB_MAX);
	b = roundf(color.w * TRGB_MAX);
	// printf("color is %d", ((t << 24) + (r << 16) + (g << 8) + b));
	return ((t << 24) + (r << 16) + (g << 8) + b);
}
