/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:23:30 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 14:22:34 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TUPLE_H
# define RT_TUPLE_H

typedef struct s_tuple {
	double	x;
	double	y;
	double	z;
	double	w;
}				t_tuple;

t_tuple		rt_tuple_make(double x, double y, double z, double w);

t_tuple		rt_point_make(double x, double y, double z);

t_tuple		rt_vector_make(double x, double y, double z);

t_tuple		rt_color_make(double t, double r, double g, double b);

/*-------------------------------MATHS_SECTION-------------------------------*/

/*rt_tuple_maths.c*/
t_tuple		rt_tuple_add(t_tuple a, t_tuple b);

t_tuple		rt_tuple_minus(t_tuple a, t_tuple b);

t_tuple		rt_tuple_negate(t_tuple	a);

t_tuple		rt_tuple_times(t_tuple a, double scale);

t_tuple		rt_tuple_divide(t_tuple a, double scale);

/*rt_vector_maths.c*/
double		rt_vector_magnitude(t_tuple	vector);

t_tuple		rt_vector_normalize(t_tuple vector);

double		rt_vector_dot(t_tuple vector1, t_tuple vector2);

t_tuple		rt_vector_cross(t_tuple vector1, t_tuple vector2);

#endif