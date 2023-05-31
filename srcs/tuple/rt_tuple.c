/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:30:41 by jyao              #+#    #+#             */
/*   Updated: 2023/05/30 12:16:44 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_tuple_make(double x, double y, double z, double w)
{
	t_tuple	tmp_tuple;

	tmp_tuple = (t_tuple){.x = x, .y = y, .z = z, .w = w};
	return (tmp_tuple);
}

t_tuple	rt_point_make(double x, double y, double z)
{
	return (rt_tuple_make(x, y, z, 1));
}

t_tuple	rt_vector_make(double x, double y, double z)
{
	return (rt_tuple_make(x, y, z, 0));
}

t_tuple	rt_color_make(double t, double r, double g, double b)
{
	return (rt_tuple_make(t, r, g, b));
}

int	rt_tuple_equal(t_tuple a, t_tuple b)
{
	return (rt_float_equal(a.x, b.x) && rt_float_equal(a.y, b.y) && \
			rt_float_equal(a.z, b.z) && rt_float_equal(a.w, b.w));
}
