/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:07:05 by jyao              #+#    #+#             */
/*   Updated: 2023/06/12 10:36:14 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static size_t	get_shape_id(void)
{
	static size_t	id;

	id++;
	if (id == UINT64_MAX)
		return (rt_error_write(ERROR_SHAPE_LIMIT, NULL), 0);
	return (id);
}

t_material	rt_material_make(\
double ambient, double diffuse, double specular, double shininess)
{
	t_material	material;

	material = (t_material){.ambient = ambient, .diffuse = diffuse, \
				.specular = specular, .shininess = shininess};
	return (material);
}

t_shape	*rt_shape_make(t_shape_type type)
{
	t_shape	*shape;

	shape = (t_shape *)ft_calloc(1, sizeof(t_shape));
	if (shape == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	shape->id = get_shape_id();
	if (shape->id == 0)
		return (rt_free_shape(shape), NULL);
	shape->type = type;
	shape->mtx_transform = rt_matrix_get_identity(4);
	shape->material = (t_material){.ambient = M_AMBIENT, .diffuse = M_DIFFUSE, \
						.specular = M_SPECULAR, .shininess = M_SHININESS};
	return (shape);
}

t_shape	*rt_shape_info_fill(t_shape *shape, t_tuple color)
{
	if (shape == NULL)
		return (NULL);
	shape->material.color = color;
	return (shape);
}

void	rt_free_shape(t_shape *shape)
{
	if (shape != NULL)
	{
		if (shape->mtx_transform != NULL)
			rt_free_matrix(shape->mtx_transform);
		if (shape->inv_mtx != NULL)
			rt_free_matrix(shape->inv_mtx);
		free(shape);
	}
}
