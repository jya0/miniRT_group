/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shape_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:27:48 by jyao              #+#    #+#             */
/*   Updated: 2023/06/13 15:46:55 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_shape	*rt_shape_transform_set(t_shape *shape, t_matrix *mtx_transform)
{
	if (shape == NULL || mtx_transform == NULL)
		return (rt_error_write(ERROR_SHAPE_TRANSFORM, NULL), shape);
	rt_free_matrix(shape->mtx_transform);
	rt_free_matrix(shape->inv_mtx);
	shape->mtx_transform = mtx_transform;
	shape->inv_mtx = rt_matrix_inverse(mtx_transform);
	rt_matrix_print(shape->inv_mtx);
	return (shape);
}
