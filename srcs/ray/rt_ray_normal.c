/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:45:34 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 09:31:29 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* we assume the point given lies on the shape and is world_point
** object_point ← inverse(shape.transform) * world_point
** object_normal ← shape_normal(object_point)
** world_normal ← transpose(inverse(shape.transform)) * object_normal
** world_normal.w ← 0
** return normalize(world_normal)
** 
** NOTE: transpose is used again after world_norm as transpose function
** changes the original copy of the mtx
*/
t_tuple	rt_ray_normal(t_shape *shape, t_tuple w_point)
{
	t_tuple		obj_norm;
	// t_tuple		world_norm;

	if (shape == NULL)
		return (rt_vector_make(0, 0, 0));
	obj_norm = rt_vector_normalize(rt_ray_normal_sphere(shape, \
		rt_matrix_times_tuple(shape->inv_mtx, w_point)));
	// world_norm = rt_matrix_times_tuple(\
	// 	rt_matrix_transpose(shape->inv_mtx), obj_norm);
	// rt_matrix_transpose(shape->inv_mtx);
	// world_norm.w = 0;
	// return (rt_vector_normalize(world_norm));
	return (rt_vector_normalize(obj_norm));
}
