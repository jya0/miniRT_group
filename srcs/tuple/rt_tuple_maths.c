/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple_maths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:52 by jyao              #+#    #+#             */
/*   Updated: 2023/05/02 13:25:23 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	res_tuple;

	res_tuple = (t_tuple){.x = a.x + b.x, .y = a.y + b.y, \
				.z = a.z + b.z, .w = a.w + b.w};
	return (res_tuple);
}

t_tuple	rt_tuple_minus(t_tuple a, t_tuple b)
{
	t_tuple	res_tuple;

	res_tuple = (t_tuple){.x = a.x - b.x, .y = a.y - b.y, \
				.z = a.z - b.z, .w = a.w - b.w};
	return (res_tuple);
}

t_tuple	rt_tuple_negate(t_tuple	a)
{
	t_tuple	res_tuple;

	res_tuple = (t_tuple){.x = a.x * -1, .y = a.y * -1, \
				.z = a.z * -1, .w = a.w * -1};
	return (res_tuple);
}

t_tuple	rt_tuple_times(t_tuple a, double scale)
{
	t_tuple	res_tuple;

	res_tuple = (t_tuple){.x = a.x * scale, .y = a.y * scale, \
				.z = a.z * scale, .w = a.w * scale};
	return (res_tuple);
}

t_tuple	rt_tuple_divide(t_tuple a, double scale)
{
	if (scale == 0)
		rt_error_write(ERROR_DIVISOR);
	return (rt_tuple_times(a, 1 / scale));
}
