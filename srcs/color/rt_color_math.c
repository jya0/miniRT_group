/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:03:13 by jyao              #+#    #+#             */
/*   Updated: 2023/06/09 08:40:12 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_color_add(t_tuple color1, t_tuple color2)
{
	return (rt_color_clamp(rt_tuple_add(color1, color2)));
}

t_tuple	rt_color_minus(t_tuple color1, t_tuple color2)
{
	return (rt_color_clamp(rt_tuple_minus(color1, color2)));
}

t_tuple	rt_color_times(t_tuple color, double scale)
{
	return (rt_color_clamp(rt_tuple_times(color, scale)));
}

t_tuple	rt_color_times_color(t_tuple color1, t_tuple color2)
{
	t_tuple	res_color;

	res_color.x = color1.x * color2.x;
	res_color.y = color1.y * color2.y;
	res_color.z = color1.z * color2.z;
	res_color.w = color1.w * color2.w;
	return (rt_color_clamp(res_color));
}
