/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_transpose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:28:30 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 13:57:11 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* diag_count goes from (0, 0) to (1, 1) to (2, 2) ... */
t_matrix	*rt_matrix_transpose(t_matrix *mtx)
{
	unsigned int	diag_count;
	unsigned int	diag_incre;
	double			tmp_val;

	if (mtx == NULL)
		return (NULL);
	if (mtx->column != mtx->row)
		return (rt_error_write(ERROR_MATRIX_FORMAT, NULL), NULL);
	diag_count = 0;
	while (diag_count < mtx->row - 1)
	{
		diag_incre = diag_count;
		while (diag_incre < mtx->column - 1)
		{
			tmp_val = mtx->matrix[diag_count][diag_incre + 1];
			mtx->matrix[diag_count][diag_incre + 1] = \
				mtx->matrix[diag_incre + 1][diag_count];
			mtx->matrix[diag_incre + 1][diag_count] = tmp_val;
			diag_incre++;
		}
		diag_count++;
	}
	return (mtx);
}
