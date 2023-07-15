/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:49:30 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/15 17:06:53 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_interx	*rt_ray_intersect_plane(t_ray ray, t_shape *plane)
{
	double		solution;
	double		divisor;
	t_interx	*interx_list;

	divisor = rt_vector_dot(ray.direction, plane->data.plane.norm_vector);
	if (rt_float_equal(divisor, 0))
		return (NULL);
	solution = (rt_vector_dot(rt_tuple_minus(plane->origin, ray.origin), \
		plane->data.plane.norm_vector)) / divisor;
	interx_list = rt_interx_list_make(1, &solution, plane, ray);
	return (interx_list);
}
