/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:37:22 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/15 17:14:16 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* o_point has to be object point */
t_tuple	rt_ray_normal_cylinder(t_shape *cylinder, t_tuple o_point)
{
	if (cylinder == NULL || cylinder->type != SHAPE_T_CYLINDER)
		return (rt_point_make(0, 0, 0));
	return (rt_tuple_minus(o_point, rt_point_make(0, 0, 0)));
}
