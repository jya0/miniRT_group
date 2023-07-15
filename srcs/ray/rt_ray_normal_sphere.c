/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:49:20 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 10:28:10 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* o_point has to be object point */
t_tuple	rt_ray_normal_sphere(t_shape *sphere, t_tuple w_point)
{
	if (sphere == NULL || sphere->type != SHAPE_T_SPHERE)
		return (rt_point_make(0, 0, 0));
	return (rt_tuple_minus(w_point, sphere->origin));
}
