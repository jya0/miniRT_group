/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_minor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:41:23 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 16:54:41 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* only works for 3x3 matrices */
double	rt_matrix_minor_3x3(\
t_matrix *mtx, unsigned int row_rm, unsigned int col_rm)
{
	t_matrix	*sub_mtx;
	double		determinant;

	if (mtx == NULL || mtx->column != mtx->row || mtx->row != 3 \
		|| row_rm >= mtx->row || col_rm >= mtx->column)
		return (rt_error_write(ERROR_MATRIX_MINOR, NULL), 0);
	sub_mtx = rt_matrix_submatrix(mtx, row_rm, col_rm);
	if (sub_mtx == NULL)
		return (0);
	determinant = rt_matrix_determinant_2x2(sub_mtx);
	rt_free_matrix(sub_mtx);
	return (determinant);
}
