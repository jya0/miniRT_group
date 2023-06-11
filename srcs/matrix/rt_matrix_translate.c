/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_translate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:08 by jyao              #+#    #+#             */
/*   Updated: 2023/06/11 10:42:04 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* returns translate matrix of size 4x4 */
t_matrix	*rt_matrix_translate(double x, double y, double z)
{
	t_matrix		*translate;
	unsigned int	i;

	translate = rt_matrix_get_identity(4);
	if (translate == NULL)
		return (NULL);
	i = 0;
	translate->matrix[i++][translate->column - 1] = x;
	translate->matrix[i++][translate->column - 1] = y;
	translate->matrix[i++][translate->column - 1] = z;
	return (translate);
}
