/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_submatrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:42:17 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 16:37:45 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static double	*matrix_submatrix_num_arr(\
t_matrix *mtx, unsigned int row_rm, \
unsigned int col_rm, unsigned int num_arr_size)
{
	unsigned int	count[3];
	double			*num_arr;

	num_arr = (double *)ft_calloc(num_arr_size, sizeof(double));
	if (num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	count[0] = 0;
	count[2] = 0;
	while (count[0] < mtx->row)
	{
		count[1] = 0;
		while (count[1] < mtx->column && count[0] != row_rm)
		{
			if (count[1] != col_rm)
				num_arr[count[2]++] = mtx->matrix[count[0]][count[1]];
			count[1]++;
		}
		count[0]++;
	}
	return (num_arr);
}

t_matrix	*rt_matrix_submatrix(\
t_matrix *mtx, unsigned int row_rm, unsigned int col_rm)
{
	t_matrix		*sub_mtx;
	double			*num_arr;

	if (mtx == NULL)
		return (NULL);
	if (mtx->column - 1 == 0 || mtx->row - 1 == 0 \
		|| row_rm >= mtx->row || col_rm >= mtx->column)
		return (rt_error_write(ERROR_MATRIX_SUBMATRIX, NULL), NULL);
	sub_mtx = (t_matrix *)rt_matrix_make(mtx->row - 1, mtx->column - 1);
	if (sub_mtx == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	num_arr = matrix_submatrix_num_arr(mtx, row_rm, col_rm, \
		sub_mtx->column * sub_mtx->row);
	rt_matrix_fill(sub_mtx, num_arr, sub_mtx->row * sub_mtx->column);
	free(num_arr);
	return (sub_mtx);
}
