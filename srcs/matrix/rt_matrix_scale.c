/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:14:47 by jyao              #+#    #+#             */
/*   Updated: 2023/05/18 11:42:25 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* returns the 4x4 scaling matrix */
t_matrix	*rt_matrix_scale(double x, double y, double z)
{
	t_matrix		*scale;
	unsigned int	diag;

	scale = rt_matrix_get_identity(4);
	if (scale == NULL)
		return (NULL);
	diag = 0;
	scale->matrix[diag][diag] = x;
	diag++;
	scale->matrix[diag][diag] = y;
	diag++;
	scale->matrix[diag][diag] = z;
	return (scale);
}
