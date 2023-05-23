/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:07:58 by jyao              #+#    #+#             */
/*   Updated: 2023/05/23 18:38:48 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_ray	rt_ray_transform(t_ray ray, t_matrix *mtx_transform)
{
	t_matrix	*ray_origin;
	t_matrix	*ray_direct;
	t_matrix	*ray_origin_transform;
	t_matrix	*ray_direct_transform;

	if (mtx_transform == NULL)
		return (rt_error_write(ERROR_RAY_TRANSFORM, NULL), ray);
	ray_origin = rt_tuple_to_matrix(ray.origin);
	ray_direct = rt_tuple_to_matrix(ray.direction);
	ray_origin_transform = rt_matrix_times_matrix(mtx_transform, ray_origin);
	ray_direct_transform = rt_matrix_times_matrix(mtx_transform, ray_direct);
	ray.origin = rt_matrix_to_tuple(ray_origin_transform, -1, 0);
	ray.direction = rt_matrix_to_tuple(ray_direct_transform, -1, 0);
	rt_free_matrix(ray_origin);
	rt_free_matrix(ray_direct);
	rt_free_matrix(ray_origin_transform);
	rt_free_matrix(ray_direct_transform);
	return (ray);
}
