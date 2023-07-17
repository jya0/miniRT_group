/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:14 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/17 14:59:20 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	*rt_plane_make(t_tuple origin, t_tuple norm_vector)
{
	t_shape		*plane;

	plane = rt_shape_make(SHAPE_T_PLANE);
	if (plane == NULL)
		return (NULL);
	plane->origin = origin;
	plane->data.plane.norm_vector = rt_vector_normalize(norm_vector);
	return (plane);
}
