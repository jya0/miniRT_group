/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect_sphere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:47:13 by jyao              #+#    #+#             */
/*   Updated: 2023/05/24 14:09:57 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* 
** brilliant explaination
** https://www.scratchapixel.com/lessons/3d-basic-rendering/
** minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html
** a = D^2
** b = 2D(O-C)
** c = |O-C|^2 - R^2
*/
t_interx	*rt_ray_intersect_sphere(t_ray ray, t_shape *sphere)
{
	t_interx	*interx_list;
	double		*solutions;
	t_tuple		origin_vector;
	double		abc[3];

	if (sphere == NULL || sphere->shape_type != TYPE_SPHERE)
		return (NULL);
	origin_vector = rt_tuple_minus(ray.origin, sphere->origin);
	abc[0] = rt_vector_dot(ray.direction, ray.direction);
	abc[1] = 2 * \
		rt_vector_dot(ray.direction, origin_vector);
	abc[2] = pow(rt_vector_magnitude(origin_vector), 2) \
		- sphere->data_shape.sphere.radius * sphere->data_shape.sphere.radius;
	solutions = rt_quadratic_formula(abc[0], abc[1], abc[2]);
	if (solutions == NULL)
		return (NULL);
	interx_list = rt_interx_list_make(QUADR_SOL, solutions, sphere, ray);
	free(solutions);
	return (interx_list);
}
