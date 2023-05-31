/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:35:58 by jyao              #+#    #+#             */
/*   Updated: 2023/05/31 09:43:02 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_shape	*rt_sphere_make(double diameter)
{
	t_shape	*sphere;

	if (diameter <= 0)
		return (rt_error_write(ERROR_SPHERE_MAKE, NULL), NULL);
	sphere = rt_shape_make(SHAPE_T_SPHERE);
	if (sphere == NULL)
		return (NULL);
	sphere->data.sphere.diameter = diameter;
	sphere->data.sphere.radius = diameter / 2;
	return (sphere);
}
