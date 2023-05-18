/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_clone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:08:43 by jyao              #+#    #+#             */
/*   Updated: 2023/05/16 14:06:38 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	check_corner_coords(\
unsigned int row, unsigned int column, t_mtx_index start, t_mtx_index end)
{
	if (start.row >= row || start.column >= column \
		|| end.row >= row || end.column >= column \
		|| start.row > end.row || start.column > end.column)
		return (rt_error_write(ERROR_MATRIX_FORMAT, NULL), 1);
	return (0);
}

/* where start is top left corner, end corner is bottom right corner */
t_matrix	*rt_matrix_clone(\
t_matrix *mtx, t_mtx_index start, t_mtx_index end)
{
	t_matrix		*clone;
	unsigned int	count[2];

	if (mtx == NULL)
		return (NULL);
	if (check_corner_coords(mtx->row, mtx->column, start, end))
		return (NULL);
	clone = (t_matrix *)rt_matrix_make(end.row - start.row + 1, \
		end.column - start.column + 1);
	if (clone == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	count[0] = 0;
	while (count[0] < clone->row)
	{
		count[1] = 0;
		while (count[1] < clone->column)
		{
			clone->matrix[count[0]][count[1]] = \
			mtx->matrix[count[0] + start.row][count[1] + start.column];
			count[1]++;
		}
		count[0]++;
	}
	return (clone);
}
