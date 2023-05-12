/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:44:59 by jyao              #+#    #+#             */
/*   Updated: 2023/05/11 17:17:04 by jyao             ###   ########.fr       */
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
