/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:03:13 by jyao              #+#    #+#             */
/*   Updated: 2023/05/10 12:57:26 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_color_clamp(t_tuple color)
{
	color.x = color.x * (color.x >= TRGB_MIN && color.x <= TRGB_MAX) \
			+ TRGB_MIN * (color.x < TRGB_MIN) \
			+ TRGB_MAX * (color.x > TRGB_MAX);
	color.y = color.y * (color.y >= TRGB_MIN && color.y <= TRGB_MAX) \
			+ TRGB_MIN * (color.y < TRGB_MIN) \
			+ TRGB_MAX * (color.y > TRGB_MAX);
	color.z = color.z * (color.z >= TRGB_MIN && color.z <= TRGB_MAX) \
			+ TRGB_MIN * (color.z < TRGB_MIN) \
			+ TRGB_MAX * (color.z > TRGB_MAX);
	color.w = color.w * (color.w >= TRGB_MIN && color.w <= TRGB_MAX) \
			+ TRGB_MIN * (color.w < TRGB_MIN) \
			+ TRGB_MAX * (color.w > TRGB_MAX);
	return (color);
}

t_tuple	rt_color_add(t_tuple color1, t_tuple color2)
{
	t_tuple	res_color;

	res_color = rt_tuple_add(color1, color2);
	res_color = rt_color_clamp(res_color);
	return (res_color);
}

t_tuple	rt_color_minus(t_tuple color1, t_tuple color2)
{
	t_tuple	res_color;

	res_color = rt_tuple_minus(color1, color2);
	res_color = rt_color_clamp(res_color);
	return (res_color);
}

t_tuple	rt_color_times(t_tuple color, double scale)
{
	t_tuple	res_color;

	res_color = rt_tuple_times(color, scale);
	res_color = rt_color_clamp(res_color);
	return (res_color);
}

t_tuple	rt_color_times_color(t_tuple color1, t_tuple color2)
{
	t_tuple	res_color;

	res_color.x = color1.x * color2.x;
	res_color.y = color1.y * color2.y;
	res_color.z = color1.z * color2.z;
	res_color.w = color1.w * color2.w;
	res_color = rt_color_clamp(res_color);
	return (res_color);
}
