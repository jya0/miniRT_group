/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:07:58 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 09:15:55 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_ray	rt_ray_transform(t_ray ray, t_matrix *mtx_transform)
{
	if (mtx_transform == NULL)
		return (rt_error_write(ERROR_RAY_TRANSFORM, NULL), ray);
	ray.origin = rt_matrix_times_tuple(mtx_transform, ray.origin);
	ray.direction = \
		rt_vector_normalize(\
		rt_matrix_times_tuple(mtx_transform, ray.direction));
	return (ray);
}
