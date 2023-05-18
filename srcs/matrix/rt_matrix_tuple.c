/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:21:57 by jyao              #+#    #+#             */
/*   Updated: 2023/05/18 11:10:00 by jyao             ###   ########.fr       */
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
t_tuple	rt_matrix_to_tuple(t_matrix	*mtx, ssize_t row, ssize_t col)
{
	t_tuple			tuple;
	double			*num_arr;
	ssize_t			i;
	ssize_t			j;

	tuple = (t_tuple){0};
	if (mtx == NULL || (row >= 0 && col >= 0) || (row < 0 && col < 0) \
		|| row >= mtx->row || col >= mtx->column)
		return (rt_error_write(ERROR_MATRIX_TUPLE, NULL), tuple);
	if (row >= 0)
		num_arr = rt_matrix_get_row(mtx, row);
	if (col >= 0)
		num_arr = rt_matrix_get_column(mtx, col);
	if (num_arr == NULL)
		return (tuple);
	j = mtx->row * (row >= 0) + mtx->column * (col >= 0) - 1;
	i = j;
	if (i >= 0)
		tuple.x = num_arr[j - i--];
	if (i >= 0)
		tuple.y = num_arr[j - i--];
	if (i >= 0)
		tuple.z = num_arr[j - i--];
	if (i >= 0)
		tuple.w = num_arr[j - i--];
	return (tuple);
}
