/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:23:30 by jyao              #+#    #+#             */
/*   Updated: 2023/05/02 15:36:33 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TUPLE_H
# define RT_TUPLE_H

# include	"minirt.h"

typedef struct s_tuple {
	double	x;
	double	y;
	double	z;
	double	w;
}				t_tuple;

t_tuple		rt_tuple_make(double x, double y, double z, double w);

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

#endif