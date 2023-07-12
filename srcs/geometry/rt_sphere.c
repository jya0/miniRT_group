/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:35:58 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 13:30:07 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_shape	*rt_sphere_make(t_tuple origin, double diameter)
{
	t_shape		*sphere;
	t_matrix	*mtx_transform;
	double		radius;

	if (diameter <= 0)
		return (rt_error_write(ERROR_SPHERE_MAKE, NULL), NULL);
	sphere = rt_shape_make(SHAPE_T_SPHERE);
	if (sphere == NULL)
		return (NULL);
	radius = diameter / 2;
	sphere->data.sphere.radius = radius;
	sphere->origin = origin;
	mtx_transform = \
		rt_matrix_times_matrix_free(\
			rt_matrix_translate(origin.x, origin.y, origin.z), \
			rt_matrix_scale(radius, radius, radius));
	rt_shape_transform_set(sphere, mtx_transform);
	return (sphere);
}
