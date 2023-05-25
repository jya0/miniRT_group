/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:14:38 by jyao              #+#    #+#             */
/*   Updated: 2023/05/24 14:10:22 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	*rt_quadratic_formula(double a, double b, double c)
{
	double	discrimnt;
	double	*solutions;

	solutions = (double *)ft_calloc(QUADR_SOL + 1, sizeof(double));
	if (solutions == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	solutions[QUADR_SOL] = NAN;
	discrimnt = b * b - 4 * a * c;
	if (discrimnt < 0)
		return (NULL);
	solutions[0] = (-b + discrimnt) / (2 * a);
	if (discrimnt == 0)
		solutions[1] = solutions[0];
	else
		solutions[1] = (-b - discrimnt) / (2 * a);
	return (solutions);
}

t_interx	*rt_ray_intersect(t_ray ray, t_shape *shape)
{
	t_interx	*intersect;
	t_matrix	*inv_mtx;

	if (shape == NULL || shape->shape_type == TYPE_INIT)
		return (NULL);
	inv_mtx = rt_matrix_inverse(shape->mtx_transform);
	ray = rt_ray_transform(ray, inv_mtx);
	rt_free_matrix(inv_mtx);
	intersect = rt_ray_intersect_sphere(ray, shape);
	return (intersect);
}
