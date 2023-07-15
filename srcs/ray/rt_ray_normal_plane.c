/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:12:19 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/13 16:12:47 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* o_point has to be object point */
t_tuple	rt_ray_normal_plane(t_shape *plane, t_tuple o_point)
{
	if (plane == NULL || plane->type != SHAPE_T_PLANE)
		return (rt_point_make(0, 0, 0));
	return (rt_tuple_minus(o_point, rt_point_make(0, 0, 0)));
}