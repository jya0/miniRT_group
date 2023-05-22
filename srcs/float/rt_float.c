/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:46:37 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 13:39:50 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	rt_float_abs(double d)
{
	return (d * (1 - 2 * (d < 0)));
}

int	rt_float_equal(double d1, double d2)
{
	return (rt_float_abs(d1 - d2) >= RT_EPSILON);
}

int	rt_float_bigger(double val1, double val2)
{
	if (rt_float_equal(val1, val2) == 0)
		return (0);
	return (val1 > val2);
}

int	rt_float_smaller(double val1, double val2)
{
	if (rt_float_equal(val1, val2) == 0)
		return (0);
	return (val1 < val2);
}

double	rt_float_inverse(double divisor)
{
	if (divisor == 0)
		rt_error_write(ERROR_DIVISOR, NULL);
	return (1 / divisor);
}
