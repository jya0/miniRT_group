/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_intersect_cylinder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:38:18 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/17 14:58:34 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	alloc_vars_cy(t_variables *vars_cy)
{
	if (vars_cy == NULL)
		return (1);
	vars_cy->tuples = (t_tuple *)ft_calloc(CVT_COUNT, sizeof(t_tuple));
	if (vars_cy->tuples == NULL)
		return (1);
	vars_cy->floats = (double *)ft_calloc(CVF_COUNT, sizeof(double));
	if (vars_cy->floats == NULL)
		return (free(vars_cy->tuples), 1);
	return (0);
}

static int	load_vars_cy(\
t_ray ray, t_shape *cylinder, t_tuple *tp, double *fl)
{
	t_ray	cy_stem;

	cy_stem = rt_ray_make(cylinder->origin, \
		rt_vector_normalize(cylinder->data.cylinder.norm_vector));
	tp[CV_A] = \
		rt_ray_position(cy_stem, cylinder->data.cylinder.height / 2);
	tp[CV_B] = \
		rt_ray_position(cy_stem, -cylinder->data.cylinder.height / 2);
	tp[CV_BA] = rt_tuple_minus(tp[CV_B], tp[CV_A]);
	tp[CV_OC] = rt_tuple_minus(ray.origin, tp[CV_A]);
	fl[CV_BABA] = rt_vector_dot(tp[CV_BA], tp[CV_BA]);
	fl[CV_BARD] = rt_vector_dot(tp[CV_BA], ray.direction);
	fl[CV_BAOC] = rt_vector_dot(tp[CV_BA], tp[CV_OC]);
	fl[CV_K2] = fl[CV_BABA] - pow(fl[CV_BARD], 2);
	fl[CV_K1] = fl[CV_BABA] * rt_vector_dot(tp[CV_OC], ray.direction) - \
		fl[CV_BAOC] * fl[CV_BARD];
	fl[CV_K0] = fl[CV_BABA] * rt_vector_dot(tp[CV_OC], tp[CV_OC]) - \
		pow(fl[CV_BAOC], 2) - \
		pow(cylinder->data.cylinder.radius, 2) * fl[CV_BABA];
	fl[CV_H] = pow(fl[CV_K1], 2) - fl[CV_K2] * fl[CV_K0];
	if (!rt_float_bigger_equal(fl[CV_H], 0))
		return (1);
	fl[CV_H] = sqrt(fl[CV_H]);
	return (0);
}

static double	cy_intersect_body(double *fl)
{
	fl[CV_T] = (-fl[CV_K1] - fl[CV_H]) / fl[CV_K2];
	fl[CV_Y] = fl[CV_BAOC] + fl[CV_T] * fl[CV_BARD];
	if (!rt_float_smaller_equal(fl[CV_Y], 0) \
		&& !rt_float_bigger_equal(fl[CV_Y], fl[CV_BABA]))
		return (fl[CV_T]);
	return (-1);
}

static double	cy_intersect_cap(double *fl)
{
	fl[CV_T] = \
		(rt_float_bigger_equal(fl[CV_Y], 0) * fl[CV_BABA] - fl[CV_BAOC]) \
			/ fl[CV_BARD];
	if (!rt_float_bigger_equal(\
		rt_float_abs(fl[CV_K1] + fl[CV_K2] * fl[CV_T]), fl[CV_H]))
		return (fl[CV_T]);
	return (-1);
}

t_interx	*rt_ray_intersect_cylinder(t_ray ray, t_shape *cylinder)
{
	t_variables	vars_cy;
	t_interx	*interx_list;
	double		solution;

	vars_cy = (t_variables){0};
	interx_list = NULL;
	solution = -1;
	if (alloc_vars_cy(&vars_cy))
		return (NULL);
	if (load_vars_cy(ray, cylinder, vars_cy.tuples, vars_cy.floats) == 0)
	{
		if (solution == -1)
			solution = cy_intersect_body(vars_cy.floats);
		if (solution == -1)
			solution = cy_intersect_cap(vars_cy.floats);
		if (solution >= 0)
			interx_list = rt_interx_list_make(1, &solution, cylinder, ray);
	}
	free(vars_cy.floats);
	free(vars_cy.tuples);
	return (interx_list);
}
