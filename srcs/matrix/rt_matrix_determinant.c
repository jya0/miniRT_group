/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_determinant.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:08:51 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 16:45:10 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* has to be a 2x2 matrix */
double	rt_matrix_determinant_2x2(t_matrix *mtx)
{
	if (mtx == NULL || mtx->column != mtx->row || mtx->row != 2)
		return (rt_error_write(ERROR_MATRIX_DETERMI, NULL), 0);
	return (mtx->matrix[0][0] * mtx->matrix[1][1] \
		- mtx->matrix[0][1] * mtx->matrix[1][0]);
}
