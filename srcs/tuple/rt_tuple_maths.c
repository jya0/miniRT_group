/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple_maths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:52 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 11:52:36 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_tuple_add(t_tuple a, t_tuple b)
{
	return (rt_tuple_make(a.x + b.x, a.y + b.y, \
			a.z + b.z, a.w + b.w));
}

t_tuple	rt_tuple_minus(t_tuple a, t_tuple b)
{
	return (rt_tuple_make(a.x - b.x, a.y - b.y, \
			a.z - b.z, a.w - b.w));
}

t_tuple	rt_tuple_times(t_tuple a, double scale)
{
	return (rt_tuple_make(a.x * scale, a.y * scale, \
			a.z * scale, a.w * scale));
}

t_tuple	rt_tuple_negate(t_tuple	a)
{
	return (rt_tuple_times(a, -1));
}

t_tuple	rt_tuple_divide(t_tuple a, double scale)
{
	if (scale == 0)
		rt_error_write(ERROR_DIVISOR, NULL);
	return (rt_tuple_times(a, 1 / scale));
}
