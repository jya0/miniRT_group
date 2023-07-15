/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:04 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/15 17:41:02 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	*rt_cylinder_make(\
	t_tuple origin,	double diameter, double height, t_tuple norm_vector)
{
	t_shape		*cylinder;
	t_matrix	*mtx_transform;
	double		radius;

	if (diameter <= 0)
		return (rt_error_write(ERROR_CYLINDER_MAKE, NULL), NULL);
	cylinder = rt_shape_make(SHAPE_T_CYLINDER);
	if (cylinder == NULL)
		return (NULL);
	radius = diameter / 2;
	cylinder->origin = origin;
	cylinder->data.cylinder.radius = radius;
	cylinder->data.cylinder.height = height;
	cylinder->data.cylinder.norm_vector = rt_vector_normalize(norm_vector);
	mtx_transform = \
		rt_matrix_times_matrix_free(\
			rt_matrix_translate(origin.x, origin.y, origin.z), \
			rt_matrix_scale(radius, radius, radius));
	rt_shape_transform_set(cylinder, mtx_transform);
	return (cylinder);
}
