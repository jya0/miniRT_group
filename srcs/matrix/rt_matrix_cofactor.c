/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_cofactor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:55:09 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 17:46:59 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static double	*matrix_cofactor_3x3_num_arr(t_matrix *mtx)
{
	double			*num_arr;
	unsigned int	count[3];
	int				sign;

	num_arr = (double *)ft_calloc(mtx->column * mtx->row, sizeof(double));
	if (num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	count[0] = 0;
	count[2] = 0;
	sign = 1;
	while (count[0] < mtx->row)
	{
		count[1] = 0;
		while (count[1] < mtx->column)
		{
			num_arr[count[2]++] = \
				rt_matrix_minor_3x3(mtx, count[0], count[1]) * sign;
			sign *= -1;
			count[1]++;
		}
		count[0]++;
	}
	return (num_arr);
}

t_matrix	*rt_matrix_cofactor_3x3(\
t_matrix *mtx, unsigned int row_rm, unsigned int col_rm)
{
	t_matrix	*cofactor;
	double		*num_arr;

	if (mtx == NULL || mtx->column != mtx->row || mtx->row != 3)
		return (rt_error_write(ERROR_MATRIX_COFACTOR, NULL), NULL);
	cofactor = rt_matrix_make(mtx->row, mtx->column);
	if (cofactor == NULL)
		return (NULL);
	num_arr = matrix_cofactor_3x3_num_arr(mtx);
	rt_matrix_fill(cofactor, num_arr, cofactor->column * cofactor->row);
	free(num_arr);
	return (cofactor);
}
