/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:14 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/15 17:40:07 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	*rt_plane_make(t_tuple origin, t_tuple norm_vector)
{
	t_shape		*plane;
	// t_matrix	*mtx_transform;

	plane = rt_shape_make(SHAPE_T_PLANE);
	if (plane == NULL)
		return (NULL);
	plane->origin = origin;
	plane->data.plane.norm_vector = rt_vector_normalize(norm_vector);
	/* mtx_transform = \
		rt_matrix_times_matrix_free(\
			rt_matrix_translate(origin.x, origin.y, origin.z), \
			rt_matrix_scale(radius, radius, radius));
	rt_shape_transform_set(plane, mtx_transform); */
	return (plane);
}
