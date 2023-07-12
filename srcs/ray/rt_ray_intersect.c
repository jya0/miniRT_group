/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:14:38 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 16:41:01 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	*rt_quadratic_formula(double a, double b, double c)
{
	double	discrimnt;
	double	discrimnt_sqrt;
	double	*solutions;

	solutions = (double *)ft_calloc(QUADR_SOL + 1, sizeof(double));
	if (solutions == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	solutions[QUADR_SOL] = NAN;
	discrimnt = b * b - 4 * a * c;
	if (discrimnt < 0)
		return (NULL);
	discrimnt_sqrt = sqrt(discrimnt);
	solutions[0] = (-b + discrimnt_sqrt) / (2 * a);
	if (discrimnt_sqrt == 0)
		solutions[1] = solutions[0];
	else
		solutions[1] = (-b - discrimnt_sqrt) / (2 * a);
	return (solutions);
}

t_interx	*rt_ray_intersect(t_ray ray, t_shape *shape)
{
	t_interx	*intersect;

	if (shape == NULL || shape->type == SHAPE_T_INIT)
		return (NULL);
	ray = rt_ray_transform(ray, shape->inv_mtx);
	intersect = rt_ray_intersect_sphere(ray, shape);
	return (intersect);
}
