/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:21:57 by jyao              #+#    #+#             */
/*   Updated: 2023/06/11 10:34:33 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_matrix	*rt_tuple_to_matrix(t_tuple tuple)
{
	t_matrix		*mtx_tuple;
	unsigned int	i;

	mtx_tuple = rt_matrix_make(4, 1);
	if (mtx_tuple == NULL)
		return (NULL);
	i = 0;
	mtx_tuple->matrix[i++][mtx_tuple->column - 1] = tuple.x;
	mtx_tuple->matrix[i++][mtx_tuple->column - 1] = tuple.y;
	mtx_tuple->matrix[i++][mtx_tuple->column - 1] = tuple.z;
	mtx_tuple->matrix[i++][mtx_tuple->column - 1] = tuple.w;
	return (mtx_tuple);
}

/* if row or col is set to negative it will not retrieve any tuple
** only row or col can be positive, but not both, they are mutex
** non negative values of row or col will be used to get that row or column
** as an arr of double
*/
t_tuple	rt_matrix_to_tuple(\
t_matrix	*mtx, ssize_t row, ssize_t col)
{
	t_tuple			tuple;
	double			*num_arr;
	ssize_t			i;
	ssize_t			j;

	tuple = (t_tuple){0};
	if (mtx == NULL || (row >= 0 && col >= 0) || (row < 0 && col < 0))
		return (rt_error_write(ERROR_MATRIX_TUPLE, NULL), tuple);
	if (row >= 0)
		num_arr = rt_matrix_get_row(mtx, row);
	if (col >= 0)
		num_arr = rt_matrix_get_column(mtx, col);
	if (num_arr == NULL)
		return (tuple);
	j = mtx->row * (col >= 0) + mtx->column * (row >= 0) - 1;
	i = j;
	tuple.x = (i >= 0) * num_arr[j - i--];
	tuple.y = (i >= 0) * num_arr[j - i--];
	tuple.z = (i >= 0) * num_arr[j - i--];
	tuple.w = (i >= 0) * num_arr[j - i--];
	free(num_arr);
	return (tuple);
}

t_tuple	rt_matrix_times_tuple(t_matrix *mtx, t_tuple tuple)
{
	t_matrix	*tuple_mtx;
	t_matrix	*res_mtx;
	t_tuple		res_tuple;

	if (mtx == NULL)
		return (tuple);
	tuple_mtx = rt_tuple_to_matrix(tuple);
	res_mtx = rt_matrix_times_matrix(mtx, tuple_mtx);
	res_tuple = rt_matrix_to_tuple(res_mtx, -1, 0);
	rt_free_matrix(tuple_mtx);
	rt_free_matrix(res_mtx);
	return (res_tuple);
}
