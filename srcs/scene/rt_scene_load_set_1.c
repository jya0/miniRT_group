/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_load_set_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:08:24 by jyao              #+#    #+#             */
/*   Updated: 2023/05/31 10:08:14 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_load_camera(t_minirt *minirt, t_element *element)
{
	struct s_camera_element	elm;

	if (minirt == NULL || element == NULL)
		return (1);
	elm = element->data.camera;
	minirt->camera = \
	rt_camera_make(\
	rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
	rt_vector_make(elm.orien_vect[0], elm.orien_vect[1], elm.orien_vect[2]), \
	elm.fov);
	if (minirt->camera == NULL)
		return (rt_error_write(ERROR_LOAD_CAM, NULL), 1);
	return (0);
}

int	rt_load_sphere(t_minirt *minirt, t_element *element)
{
	struct s_sphere_element	elm;
	t_scene					*scene;

	if (minirt == NULL || element == NULL)
		return (1);
	elm = element->data.sphere;
	scene = minirt->scene;
	if (scene->shapes_count >= scene->shapes_total)
		return (rt_error_write(ERROR_ELM_OVERFLOW, NULL), 1);
	scene->shapes[scene->shapes_count] = rt_sphere_make(elm.diameter);
	if (scene->shapes[scene->shapes_count] == NULL)
		return (rt_error_write(ERROR_LOAD_SPHERE, NULL), 1);
	rt_shape_info_fill(\
		scene->shapes[scene->shapes_count], \
		rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
		elm.trgb);
	scene->shapes_count++;
	return (0);
}
