/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_normal_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:37:22 by ooutabac          #+#    #+#             */
/*   Updated: 2023/07/15 23:29:03 by jyao             ###   ########.fr       */
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

static t_tuple	calc_normal_cy(\
t_shape *cylinder, t_tuple w_point, t_tuple *tp, double *fl)
{
	t_ray	cy_stem;

	cy_stem = rt_ray_make(cylinder->origin, \
		rt_vector_normalize(cylinder->data.cylinder.norm_vector));
	tp[CV_A] = \
		rt_ray_position(cy_stem, cylinder->data.cylinder.height / 2);
	tp[CV_B] = \
		rt_ray_position(cy_stem, -cylinder->data.cylinder.height / 2);
	tp[CV_PA] = rt_tuple_minus(w_point, tp[CV_A]);
	if (rt_float_equal(rt_vector_dot(\
		tp[CV_PA], cylinder->data.cylinder.norm_vector), 0))
		return (rt_tuple_negate(cylinder->data.cylinder.norm_vector));
	if (rt_float_equal(rt_vector_dot(\
		rt_tuple_minus(w_point, tp[CV_B]), \
		cylinder->data.cylinder.norm_vector), 0))
		return (cylinder->data.cylinder.norm_vector);
	tp[CV_BA] = rt_tuple_minus(tp[CV_B], tp[CV_A]);
	fl[CV_BABA] = rt_vector_dot(tp[CV_BA], tp[CV_BA]);
	fl[CV_H] = rt_vector_dot(tp[CV_PA], tp[CV_BA]) / fl[CV_BABA];
	return (rt_tuple_divide(\
				rt_tuple_minus(tp[CV_PA], \
					rt_tuple_times(tp[CV_BA], \
						fl[CV_H])), \
				cylinder->data.cylinder.radius));
}

/* o_point has to be object point */
t_tuple	rt_ray_normal_cylinder(t_shape *cylinder, t_tuple w_point)
{
	t_variables	vars_cy;
	t_tuple		w_normal;

	if (cylinder == NULL || cylinder->type != SHAPE_T_CYLINDER)
		return (rt_point_make(0, 0, 0));
	vars_cy = (t_variables){0};
	if (alloc_vars_cy(&vars_cy))
		return (rt_point_make(0, 0, 0));
	w_normal = \
		calc_normal_cy(cylinder, w_point, vars_cy.tuples, vars_cy.floats);
	free(vars_cy.floats);
	free(vars_cy.tuples);
	return (w_normal);
}
