/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:46:37 by jyao              #+#    #+#             */
/*   Updated: 2023/05/11 14:15:05 by jyao             ###   ########.fr       */
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

double	rt_float_inverse(double divisor)
{
	if (divisor == 0)
		rt_error_write(ERROR_DIVISOR, NULL);
	return (1 / divisor);
}
