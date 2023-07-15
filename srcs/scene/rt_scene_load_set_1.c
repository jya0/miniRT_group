/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_load_set_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:08:24 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 14:34:04 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_load_camera(t_scene *scene, t_element *element)
{
	struct s_camera_element	elm;

	if (scene == NULL || element == NULL)
		return (1);
	elm = element->data.camera;
	scene->camera = \
	rt_camera_make(\
		rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
		rt_vector_make(elm.orien_vect[0], \
			elm.orien_vect[1], elm.orien_vect[2]), \
		elm.fov);
	if (scene->camera == NULL)
		return (rt_error_write(ERROR_LOAD_CAM, NULL), 1);
	return (0);
}

int	rt_load_ambient(t_scene *scene, t_element *element)
{
	struct s_ambient_element	elm;

	if (scene == NULL || element == NULL)
		return (1);
	elm = element->data.ambient;
	scene->ambient = \
		rt_ambient_make(rt_trgb_to_color(elm.trgb), elm.intensity);
	if (scene->ambient == NULL)
		return (rt_error_write(ERROR_LOAD_AMBIENT, NULL), 1);
	return (0);
}

int	rt_load_light(t_scene *scene, t_element *element)
{
	struct s_light_element	elm;

	if (scene == NULL || element == NULL)
		return (1);
	elm = element->data.light;
	scene->light = \
		rt_light_make(\
			rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
			elm.intensity);
	if (scene->light == NULL)
		return (rt_error_write(ERROR_LOAD_LIGHT, NULL), 1);
	return (0);
}

int	rt_load_sphere(t_scene *scene, t_element *element)
{
	struct s_sphere_element	elm;

	if (scene == NULL || element == NULL)
		return (1);
	elm = element->data.sphere;
	if (scene->shapes_count >= scene->shapes_total)
		return (rt_error_write(ERROR_ELM_OVERFLOW, NULL), 1);
	scene->shapes[scene->shapes_count] = \
		rt_sphere_make(rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
			elm.diameter);
	if (scene->shapes[scene->shapes_count] == NULL)
		return (rt_error_write(ERROR_LOAD_SPHERE, NULL), 1);
	rt_shape_info_fill(\
		scene->shapes[scene->shapes_count], \
		rt_trgb_to_color(elm.trgb));
	scene->shapes_count++;
	return (0);
}

int	rt_load_plane(t_scene *scene, t_element *element)
{
	struct s_plane_element	elm;

	if (scene == NULL || element == NULL)
		return (1);
	elm = element->data.plane;
	if (scene->shapes_count >= scene->shapes_total)
		return (rt_error_write(ERROR_ELM_OVERFLOW, NULL), 1);
	scene->shapes[scene->shapes_count] = \
		rt_plane_make(rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
			rt_vector_make(elm.norm_vect[0], elm.norm_vect[1], elm.norm_vect[2]));
	if (scene->shapes[scene->shapes_count] == NULL)
		return (rt_error_write(ERROR_LOAD_PLANE, NULL), 1);
	rt_shape_info_fill(\
		scene->shapes[scene->shapes_count], \
		rt_trgb_to_color(elm.trgb));
	scene->shapes_count++;
	return (0);
}

int	rt_load_cylinder(t_scene *scene, t_element *element)
{
	struct s_cylinder_element	elm;

	if (scene == NULL || element == NULL)
		return (1);
	elm = element->data.cylinder;
	if (scene->shapes_count >= scene->shapes_total)
		return (rt_error_write(ERROR_ELM_OVERFLOW, NULL), 1);
	scene->shapes[scene->shapes_count] = \
		rt_cylinder_make(rt_point_make(elm.coord[0], elm.coord[1], elm.coord[2]), \
			elm.diameter, elm.height, rt_vector_make(elm.norm_vect[0], elm.norm_vect[1], elm.norm_vect[2]));
	if (scene->shapes[scene->shapes_count] == NULL)
		return (rt_error_write(ERROR_LOAD_CYLINDER, NULL), 1);
	rt_shape_info_fill(\
		scene->shapes[scene->shapes_count], \
		rt_trgb_to_color(elm.trgb));
	scene->shapes_count++;
	return (0);
}
