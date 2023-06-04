/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:34:57 by jyao              #+#    #+#             */
/*   Updated: 2023/06/04 18:22:35 by jyao             ###   ########.fr       */
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

void	rt_free_scene_obj(t_scene_obj *scene_obj)
{
	if (scene_obj != NULL)
	{
		free(scene_obj);
	}
}
