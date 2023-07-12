/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect_sphere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:47:13 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 16:44:17 by jyao             ###   ########.fr       */
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
	t_tuple		sp_to_ray;
	double		abc[3];

	if (sphere == NULL || sphere->type != SHAPE_T_SPHERE)
		return (NULL);
	sp_to_ray = rt_tuple_minus(ray.origin, rt_point_make(0, 0, 0));
	abc[0] = rt_vector_dot(ray.direction, ray.direction);
	abc[1] = 2 * rt_vector_dot(ray.direction, sp_to_ray);
	abc[2] = rt_vector_dot(sp_to_ray, sp_to_ray) - 1;
	solutions = rt_quadratic_formula(abc[0], abc[1], abc[2]);
	if (solutions == NULL)
		return (NULL);
	interx_list = rt_interx_list_make(QUADR_SOL, solutions, sphere, ray);
	free(solutions);
	return (interx_list);
}
