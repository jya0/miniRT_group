/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:44:59 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 14:08:32 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	*rt_matrix_get_row(t_matrix *mtx, unsigned int row)
{
	double			*num_arr;
	unsigned int	i;

	if (mtx == NULL)
		return (NULL);
	if (row > mtx->row)
		return (rt_error_write(ERROR_MATRIX_READ, NULL), NULL);
	num_arr = (double *)ft_calloc(mtx->column, sizeof(double));
	if (num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	i = 0;
	while (i < mtx->column)
	{
		num_arr[i] = mtx->matrix[row][i];
		i++;
	}
	return (num_arr);
}

double	*rt_matrix_get_column(t_matrix *mtx, unsigned int column)
{
	double			*num_arr;
	unsigned int	i;

	if (mtx == NULL)
		return (NULL);
	if (column > mtx->column)
		return (rt_error_write(ERROR_MATRIX_READ, NULL), NULL);
	num_arr = (double *)ft_calloc(mtx->row, sizeof(double));
	if (num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	i = 0;
	while (i < mtx->row)
	{
		num_arr[i] = mtx->matrix[i][column];
		i++;
	}
	return (num_arr);
}

static double	*get_identity_num_arr(unsigned int side_len)
{
	double			*id_num_arr;
	unsigned int	count[2];

	id_num_arr = (double *)ft_calloc(side_len * side_len, sizeof(double));
	if (id_num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	count[0] = 0;
	count[1] = 0;
	while (count[0] < side_len)
	{
		id_num_arr[count[0] * side_len + count[1]] = 1;
		count[0]++;
		count[1]++;
	}
	return (id_num_arr);
}

t_matrix	*rt_matrix_get_identity(t_matrix *mtx)
{
	t_matrix	*id_mtx;
	double		*id_num_arr;

	if (mtx->row != mtx->column)
		return (rt_error_write(ERROR_MATRIX_IDENTITY, NULL), NULL);
	id_mtx = rt_matrix_make(mtx->row, mtx->column);
	id_num_arr = get_identity_num_arr(mtx->row);
	rt_matrix_fill(id_mtx, id_num_arr, mtx->row * mtx->column);
	free(id_num_arr);
	return (id_mtx);
}
