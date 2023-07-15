/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:49:30 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/15 16:10:26 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	rt_vector_dot2(t_tuple vector1, t_tuple vector2)
{
	return (vector1.x * vector2.x + \
			vector1.y * vector2.y + \
			vector1.z * vector2.z);
}

t_interx	*rt_ray_intersect_plane(t_ray ray, t_shape *plane)
{
	double	value[1];
	t_interx	*interx_list;

	value[0] = -(rt_vector_dot2(ray.origin, plane->origin) + plane->origin.w)	\
		/ (rt_vector_dot2(ray.direction, plane->origin));
	interx_list = rt_interx_list_make(1, value, plane, ray);
	return (interx_list);
}
