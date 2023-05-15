/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:08 by jyao              #+#    #+#             */
/*   Updated: 2023/05/12 17:08:09 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* Fills the matrix from left to right, top to bottom */
t_matrix	*rt_matrix_fill(t_matrix *mtx_to_fill, \
double *num_arr, unsigned int num_count)
{
	unsigned int	i;
	unsigned int	j;

	if (mtx_to_fill == NULL || num_arr == NULL \
		|| num_count > (mtx_to_fill->row * mtx_to_fill->column))
		return (rt_error_write(ERROR_MATRIX_ASSIGN, NULL), mtx_to_fill);
	i = 0;
	while (i < mtx_to_fill->row && num_count != 0)
	{
		j = 0;
		while (j < mtx_to_fill->column && num_count != 0)
		{
			mtx_to_fill->matrix[i][j] = num_arr[i * mtx_to_fill->column + j];
			j++;
			num_count--;
		}
		i++;
	}
	return (mtx_to_fill);
}

void	rt_free_matrix(t_matrix *mtx_to_free)
{
	if (mtx_to_free != NULL)
	{
		if (mtx_to_free->matrix != NULL)
		{
			while (mtx_to_free->row != 0)
				free(mtx_to_free->matrix[--mtx_to_free->row]);
			free(mtx_to_free->matrix);
		}
		free(mtx_to_free);
	}
}

static t_matrix	*alloc_matrix(unsigned int row, unsigned int column)
{
	t_matrix		*res_matrix;
	unsigned int	i;

	res_matrix = (t_matrix *)ft_calloc(1, sizeof(t_matrix));
	if (res_matrix == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	res_matrix->matrix = (double **)ft_calloc(row, sizeof(double *));
	if (res_matrix->matrix == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), free(res_matrix), NULL);
	i = 0;
	while (i < row)
	{
		res_matrix->matrix[i] = (double *)ft_calloc(column, sizeof(double));
		if (res_matrix->matrix[i] == NULL)
		{
			while (i != 0)
				free(res_matrix->matrix[--i]);
			return (rt_error_write(ERROR_MEM_ALLOC, NULL), \
				free(res_matrix), NULL);
		}
		i++;
	}
	return (res_matrix);
}

int	rt_matrix_equal(t_matrix *mtx1, t_matrix *mtx2)
{
	unsigned int	i;
	unsigned int	j;

	if (mtx1->row != mtx2->row || mtx1->column != mtx2->column)
		return (1);
	i = 0;
	while (i < mtx1->row)
	{
		j = 0;
		while (j < mtx1->column)
		{
			if (rt_float_equal(mtx1->matrix[i][j], mtx2->matrix[i][j]) != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_matrix	*rt_matrix_make(unsigned int row, unsigned int column)
{
	t_matrix	*res_matrix;

	if (row <= 0 || column <= 0)
		return (rt_error_write(ERROR_MATRIX_FORMAT, NULL), NULL);
	res_matrix = alloc_matrix(row, column);
	if (res_matrix == NULL)
		return (NULL);
	res_matrix->row = row;
	res_matrix->column = column;
	return (res_matrix);
}
