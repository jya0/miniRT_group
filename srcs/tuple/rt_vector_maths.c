/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:55 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 08:43:22 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	rt_vector_magnitude(t_tuple	vector)
{
	double	pythagoras_product;

	if (vector.w != 0)
		rt_error_write(ERROR_NOT_VECTOR, NULL);
	pythagoras_product = vector.x * vector.x + vector.y * vector.y \
	+ vector.z * vector.z + vector.w * vector.w;
	return (sqrt(pythagoras_product));
}

t_tuple	rt_vector_normalize(t_tuple vector)
{
	if (vector.w != 0)
		rt_error_write(ERROR_NOT_VECTOR, NULL);
	return (rt_tuple_divide(vector, rt_vector_magnitude(vector)));
}

/* w is still included in the calculation as the guide mentioned
** the dot product calculates up to any dimensions
*/
double	rt_vector_dot(t_tuple vector1, t_tuple vector2)
{
	return (vector1.x * vector2.x + \
			vector1.y * vector2.y + \
			vector1.z * vector2.z + \
			vector1.w * vector2.w);
}

/* cross product gets more complex with 4 dimensions,
** as we only need 3D vectors here we keep it simple.
*/
t_tuple	rt_vector_cross(t_tuple vector1, t_tuple vector2)
{
	t_tuple	res;

	if (vector1.w != 0 || vector2.w != 0)
		rt_error_write(ERROR_NOT_VECTOR, NULL);
	res = rt_vector_make(\
			vector1.y * vector2.z - vector1.z * vector2.y, \
			vector1.z * vector2.x - vector1.x * vector2.z, \
			vector1.x * vector2.y - vector1.y * vector2.x);
	if (rt_float_equal(rt_vector_magnitude(res), 0))
		rt_error_write(ERROR_PARALLEL_VEC, NULL);
	return (res);
}
