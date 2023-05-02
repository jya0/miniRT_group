/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:55 by jyao              #+#    #+#             */
/*   Updated: 2023/05/02 15:36:34 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	rt_vector_magnitude(t_tuple	vector)
{
	double	pythagoras_product;

	if (vector.w != 0)
		rt_error_write(ERROR_NOT_VECTOR);
	pythagoras_product = vector.x * vector.x + vector.y * vector.y \
	+ vector.z * vector.z + vector.w * vector.w;
	return (sqrt(pythagoras_product));
}

t_tuple	rt_vector_normalize(t_tuple vector)
{
	if (vector.w != 0)
		rt_error_write(ERROR_NOT_VECTOR);
	return (rt_tuple_divide(vector, rt_vector_magnitude(vector)));
}
