/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect_cylinder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:38:18 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/13 19:07:15 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	rt_vector_dot2(t_tuple vector1, t_tuple vector2)
{
	return (vector1.x * vector2.x + \
			vector1.y * vector2.y + \
			vector1.z * vector2.z);
}

t_interx	*rt_ray_intersect_cylinder(t_ray ray, t_shape *cylinder)
{
	double	value[2];
	t_interx	*interx_list;
	
	value[0] = 
	
	return (interx_list);
}
