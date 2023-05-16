/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_cofactor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:55:09 by jyao              #+#    #+#             */
/*   Updated: 2023/05/16 12:51:16 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static double	*matrix_cofactor_num_arr(t_matrix *mtx)
{
	double			*num_arr;
	t_matrix		*s_mtx;
	unsigned int	i[2];
	int				sign;

	num_arr = (double *)ft_calloc(mtx->column * mtx->row, sizeof(double));
	if (num_arr == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	i[0] = 0;
	sign = 1;
	while (i[0] < mtx->row)
	{
		i[1] = 0;
		while (i[1] < mtx->column)
		{
			s_mtx = rt_matrix_submatrix(mtx, i[0], i[1]);
			num_arr[i[0] * mtx->column + i[1]] = rt_matrix_detmnt(s_mtx) * sign;
			rt_free_matrix(s_mtx);
			sign *= -1;
			i[1]++;
		}
		sign *= -1;
		i[0]++;
	}
	return (num_arr);
}

/* finds determinant for every element and also gets the
** sign for cofactor	+-+
** 						-+-
** 						+-+
*/
t_matrix	*rt_matrix_cofactor(t_matrix *mtx)
{
	t_matrix	*cofactor;
	double		*num_arr;

	if (mtx == NULL || mtx->column != mtx->row)
		return (rt_error_write(ERROR_MATRIX_COFACTOR, NULL), NULL);
	cofactor = rt_matrix_make(mtx->row, mtx->column);
	if (cofactor == NULL)
		return (NULL);
	num_arr = matrix_cofactor_num_arr(mtx);
	rt_matrix_fill(cofactor, num_arr, cofactor->column * cofactor->row);
	free(num_arr);
	return (cofactor);
}
