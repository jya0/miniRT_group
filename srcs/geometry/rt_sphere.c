/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:35:58 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 14:36:29 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_shape	*rt_sphere_make(double diameter)
{
	t_shape	*sphere;

	sphere = rt_shape_make();
	if (sphere == NULL || diameter <= 0)
		return (NULL);
	sphere->shape_type = TYPE_SPHERE;
	sphere->data_shape.sphere.diameter = diameter;
	sphere->data_shape.sphere.radius = diameter / 2;
	return (sphere);
}
