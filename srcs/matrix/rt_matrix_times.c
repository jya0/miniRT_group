/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_times.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:17:38 by jyao              #+#    #+#             */
/*   Updated: 2023/07/17 14:56:05 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

// res = fma(num_arr1[i], num_arr2[i], res);
static double	arr_dot_arr(\
double *num_arr1, unsigned int num_arr1_len, \
double *num_arr2, unsigned int num_arr2_len)
{
	double			res;
	unsigned int	i;

	if (num_arr1 == NULL || num_arr2 == NULL)
		return (0);
	res = 0;
	i = 0;
	while (i < num_arr1_len && i < num_arr2_len)
	{
		res += num_arr1[i] * num_arr2[i];
		i++;
	}
	return (res);
}

static double	*matrix_times_matrix_res(t_matrix *mtx1, t_matrix *mtx2)
{
	double			*num_arr;
	double			*row;
	double			*column;
	unsigned int	count[2];

	num_arr = (double *)ft_calloc(mtx1->row * mtx2->column, sizeof(double));
	if (num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	count[0] = 0;
	while (count[0] < mtx1->row)
	{
		row = rt_matrix_get_row(mtx1, count[0]);
		count[1] = 0;
		while (count[1] < mtx2->column)
		{
			column = rt_matrix_get_column(mtx2, count[1]);
			num_arr[count[0] * mtx2->column + count[1]] = \
				arr_dot_arr(row, mtx1->column, column, mtx2->row);
			free(column);
			count[1]++;
		}
		free(row);
		count[0]++;
	}
	return (num_arr);
}

/* WORKS UP TO ANY MATRIX DIMENSIONS !!! */
t_matrix	*rt_matrix_times_matrix(t_matrix *mtx1, t_matrix *mtx2)
{
	t_matrix	*res_matrix;
	double		*num_arr;

	if (mtx1 == NULL || mtx2 == NULL)
		return (NULL);
	if (mtx1->column != mtx2->row)
		return (rt_error_write(ERROR_MATRIX_FORMAT, NULL), NULL);
	res_matrix = rt_matrix_make(mtx1->row, mtx2->column);
	num_arr = matrix_times_matrix_res(mtx1, mtx2);
	rt_matrix_fill(res_matrix, num_arr, mtx1->row * mtx2->column);
	free(num_arr);
	return (res_matrix);
}

/*
** here mtx1 and mtx2 must be malloced!
** very risk function I know!
** use only if mtx1 and mtx2 are malloced and will not be
** used ever again after calling this function!
*/
t_matrix	*rt_matrix_times_matrix_free(t_matrix *mtx1, t_matrix *mtx2)
{
	t_matrix	*res_matrix;
	double		*num_arr;

	if (mtx1 == NULL || mtx2 == NULL)
		return (NULL);
	if (mtx1->column != mtx2->row)
		return (rt_error_write(ERROR_MATRIX_FORMAT, NULL), NULL);
	res_matrix = rt_matrix_make(mtx1->row, mtx2->column);
	num_arr = matrix_times_matrix_res(mtx1, mtx2);
	rt_matrix_fill(res_matrix, num_arr, mtx1->row * mtx2->column);
	free(num_arr);
	rt_free_matrix(mtx1);
	rt_free_matrix(mtx2);
	return (res_matrix);
}

t_matrix	*rt_matrix_times(t_matrix *mtx, double scale)
{
	unsigned int	i;
	unsigned int	j;

	if (mtx == NULL)
		return (NULL);
	i = 0;
	while (i < mtx->row)
	{
		j = 0;
		while (j < mtx->column)
		{
			mtx->matrix[i][j] *= scale;
			j++;
		}
		i++;
	}
	return (mtx);
}
