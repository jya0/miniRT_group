/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:53:27 by jyao              #+#    #+#             */
/*   Updated: 2023/05/23 13:23:17 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FLOAT_H
# define RT_FLOAT_H

# define RT_EPSILON	0.00001f

double		rt_float_abs(double d);

int			rt_float_equal(double d1, double d2);

int			rt_float_bigger_equal(double val1, double val2);

int			rt_float_smaller_equal(double val1, double val2);

double		rt_float_inverse(double divisor);

#endif