/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:53:27 by jyao              #+#    #+#             */
/*   Updated: 2023/05/02 13:20:09 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FLOAT_H
# define RT_FLOAT_H

# define RT_EPSILON	0.00001f

double		rt_float_abs(double d);

int			rt_float_equal(double d1, double d2);

#endif