/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:45:34 by jyao              #+#    #+#             */
/*   Updated: 2023/06/03 15:08:29 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* we assume the point given lies on the shape and is world_point
** object_point ← inverse(shape.transform) * world_point
** object_normal ← shape_normal(object_point)
** world_normal ← transpose(inverse(shape.transform)) * object_normal
** world_normal.w ← 0
** return normalize(world_normal)
*/
t_tuple	rt_ray_normal(t_shape *shape, t_tuple w_point)
{
	t_matrix	*inv_mtx;
	t_tuple		obj_norm;
	t_tuple		world_norm;

	if (shape == NULL)
		return (rt_vector_make(0, 0, 0));
	inv_mtx = rt_matrix_inverse(shape->mtx_transform);
	obj_norm = rt_ray_normal_sphere(shape, \
		rt_matrix_times_tuple(inv_mtx, w_point));
	world_norm = rt_matrix_times_tuple(rt_matrix_transpose(inv_mtx), obj_norm);
	world_norm.w = 0;
	rt_free_matrix(inv_mtx);
	return (rt_vector_normalize(world_norm));
}
