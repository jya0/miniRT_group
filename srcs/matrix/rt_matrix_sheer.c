/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_sheer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:38:26 by jyao              #+#    #+#             */
/*   Updated: 2023/05/18 13:43:33 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* Returns a 4x4 matrix that will change the x, y, z values according to each
** of the individual component's counterparts.
** i.e. x is changed in relation to the value specified for y and z in x_rela
*/
t_matrix	*rt_matrix_sheer(t_tuple x_rela, t_tuple y_rela, t_tuple z_rela)
{
	t_matrix	*sheer;

	sheer = rt_matrix_get_identity(4);
	if (sheer == NULL)
		return (NULL);
	sheer->matrix[0][1] = x_rela.y;
	sheer->matrix[0][2] = x_rela.z;
	sheer->matrix[1][0] = y_rela.x;
	sheer->matrix[1][2] = y_rela.z;
	sheer->matrix[2][0] = z_rela.x;
	sheer->matrix[2][1] = z_rela.y;
	return (sheer);
}
