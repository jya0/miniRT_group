/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_inverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:51 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 08:40:16 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* finding the inverse of a matrix any dimension! */
t_matrix	*rt_matrix_inverse(t_matrix *mtx)
{
	t_matrix	*res_mtx;
	double		detmnt;

	if (mtx == NULL || mtx->row != mtx->column)
		return (rt_error_write(ERROR_MATRIX_INVERSE, NULL), NULL);
	detmnt = rt_matrix_detmnt(mtx);
	if (detmnt == 0)
		return (rt_error_write(ERROR_MATRIX_INVERSE, NULL), NULL);
	res_mtx = rt_matrix_cofactor(mtx);
	if (res_mtx == NULL)
		return (NULL);
	rt_matrix_transpose(res_mtx);
	rt_matrix_times(res_mtx, rt_float_inverse(detmnt));
	return (res_mtx);
}
