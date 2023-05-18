/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:55:53 by jyao              #+#    #+#             */
/*   Updated: 2023/05/18 12:56:43 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* Returns a 4x4 matrix that will rotate degrees in the x axis clockwise
** facing the negative x direction
*/
t_matrix	*rt_matrix_rotate_x(double radians)
{
	t_matrix	*rotate_x;

	rotate_x = rt_matrix_get_identity(4);
	if (rotate_x == NULL)
		return (NULL);
	rotate_x->matrix[1][1] = cos(radians);
	rotate_x->matrix[1][2] = -sin(radians);
	rotate_x->matrix[2][1] = sin(radians);
	rotate_x->matrix[2][2] = cos(radians);
	return (rotate_x);
}

/* Returns a 4x4 matrix that will rotate degrees in the y axis clockwise
** facing the negative y direction
*/
t_matrix	*rt_matrix_rotate_y(double radians)
{
	t_matrix	*rotate_y;

	rotate_y = rt_matrix_get_identity(4);
	if (rotate_y == NULL)
		return (NULL);
	rotate_y->matrix[0][0] = cos(radians);
	rotate_y->matrix[0][2] = sin(radians);
	rotate_y->matrix[2][0] = -sin(radians);
	rotate_y->matrix[2][2] = cos(radians);
	return (rotate_y);
}

/* Returns a 4x4 matrix that will rotate degrees in the z axis clockwise
** facing the negative z direction
*/
t_matrix	*rt_matrix_rotate_z(double radians)
{
	t_matrix	*rotate_z;

	rotate_z = rt_matrix_get_identity(4);
	if (rotate_z == NULL)
		return (NULL);
	rotate_z->matrix[0][0] = cos(radians);
	rotate_z->matrix[0][1] = -sin(radians);
	rotate_z->matrix[1][0] = sin(radians);
	rotate_z->matrix[1][1] = cos(radians);
	return (rotate_z);
}
