/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_detmnt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:08:51 by jyao              #+#    #+#             */
/*   Updated: 2023/05/16 10:55:32 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* has to be a 2x2 matrix */
double	rt_matrix_detmnt_2x2(t_matrix *mtx)
{
	if (mtx == NULL || mtx->column != mtx->row || mtx->row != 2)
		return (rt_error_write(ERROR_MATRIX_DETERMI, NULL), 0);
	return (mtx->matrix[0][0] * mtx->matrix[1][1] \
		- mtx->matrix[0][1] * mtx->matrix[1][0]);
}

static double	calculate_determinant(\
t_matrix *mtx, double *sub_detmnts, unsigned int size)
{
	unsigned int	i;
	int				sign;
	double			detmnt;

	if (mtx == NULL || sub_detmnts == NULL)
		return (0);
	sign = 1;
	detmnt = 0;
	i = 0;
	while (i < size)
	{
		detmnt += sign * sub_detmnts[i] * mtx->matrix[0][i];
		sign *= -1;
		i++;
	}
	return (detmnt);
}

double	rt_matrix_detmnt(t_matrix *mtx)
{
	t_matrix		*sub_mtx;
	double			*sub_detmnts;
	double			detmnt;
	unsigned int	i;

	if (mtx == NULL || mtx->column != mtx->row)
		return (rt_error_write(ERROR_MATRIX_DETERMI, NULL), 0);
	if (mtx->row == 2)
		return (rt_matrix_detmnt_2x2(mtx));
	sub_detmnts = (double *)ft_calloc(mtx->column, sizeof(double));
	if (sub_detmnts == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), 0);
	i = 0;
	while (i < mtx->row)
	{
		sub_mtx = rt_matrix_submatrix(mtx, 0, i);
		sub_detmnts[i] = rt_matrix_detmnt(sub_mtx);
		rt_free_matrix(sub_mtx);
		i++;
	}
	detmnt = calculate_determinant(mtx, sub_detmnts, mtx->column);
	free(sub_detmnts);
	return (detmnt);
}
