/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:34:57 by jyao              #+#    #+#             */
/*   Updated: 2023/07/17 15:07:46 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_scene_obj	*rt_scene_obj_make(t_scene_obj_type type)
{
	t_scene_obj	*scene_obj;

	scene_obj = (t_scene_obj *)ft_calloc(1, sizeof(t_scene_obj));
	if (scene_obj == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	scene_obj->type = type;
	return (scene_obj);
}

t_scene_obj	*rt_light_make(t_tuple coord, double intensity)
{
	t_scene_obj	*light;

	light = rt_scene_obj_make(OBJ_T_CAMERA);
	if (light == NULL)
		return (NULL);
	light->data.light.coord = coord;
	light->data.light.intensity = intensity;
	return (light);
}

t_scene_obj	*rt_ambient_make(t_tuple color, double intensity)
{
	t_scene_obj	*ambient;

	ambient = rt_scene_obj_make(OBJ_T_AMBIENT);
	if (ambient == NULL)
		return (NULL);
	ambient->data.ambient.color = color;
	ambient->data.ambient.intensity = intensity;
	return (ambient);
}

t_scene_obj	*rt_scene_obj_transform_set(\
t_scene_obj *scene_obj, t_matrix *mtx_transform)
{
	if (scene_obj == NULL || mtx_transform == NULL)
		return (rt_error_write(ERROR_SHAPE_TRANSFORM, NULL), scene_obj);
	rt_free_matrix(scene_obj->mtx_transform);
	rt_free_matrix(scene_obj->inv_mtx);
	scene_obj->mtx_transform = mtx_transform;
	scene_obj->inv_mtx = rt_matrix_inverse(mtx_transform);
	return (scene_obj);
}

void	rt_free_scene_obj(t_scene_obj *scene_obj)
{
	if (scene_obj != NULL)
	{
		rt_free_matrix(scene_obj->mtx_transform);
		rt_free_matrix(scene_obj->inv_mtx);
		free(scene_obj);
	}
}
