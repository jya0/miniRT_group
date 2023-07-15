/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:45:34 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 17:13:42 by ooutabac         ###   ########.fr       */
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
	t_tuple		world_norm;

	if (shape == NULL)
		return (rt_vector_make(0, 0, 0));
	if (shape->type == SHAPE_T_SPHERE)
		world_norm = rt_ray_normal_sphere(shape, w_point);
	if (shape->type == SHAPE_T_PLANE)
		world_norm = rt_ray_normal_plane(shape);
	// if (shape->type == SHAPE_T_CYLINDER)
	// 	world_norm = rt_ray_normal_cylinder(shape);
	return (rt_vector_normalize(world_norm));
}
