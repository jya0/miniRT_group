/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:53:27 by jyao              #+#    #+#             */
/*   Updated: 2023/05/30 12:38:13 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FLOAT_H
# define RT_FLOAT_H

# define RT_EPSILON	0.00001f

/* rt_float.c */
double		rt_float_abs(double d);

int			rt_float_equal(double d1, double d2);

int			rt_float_bigger_equal(double val1, double val2);

int			rt_float_smaller_equal(double val1, double val2);

double		rt_float_inverse(double divisor);

/* rt_float_maths.c */
double		rt_deg_to_rad(float degrees);

#endif