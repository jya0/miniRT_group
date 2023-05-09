/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_element_set_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:33 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 20:26:15 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_parse_ambient(t_element *element)
{
	static int	ambient_flag;

	if (element == NULL)
		return (1);
	if (ambient_flag != 0)
		return (rt_error_write(ERROR_ELEMENT_DUP, element->id_str), 1);
	if (rt_parse_element_argc(element->info) != ARGC_AMBIENT)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->element_type.ambient.intensity = \
		rt_parse_element_double(element->info[1]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		element->element_type.ambient.rgb, \
			element->info[2], ",", COLOR_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->element_type.ambient.intensity, \
		INTENSITY_MIN, INTENSITY_MAX) != 0 \
			|| rt_check_int_arr_range(\
			element->element_type.ambient.rgb, \
			RGB_MIN, RGB_MAX, COLOR_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	ambient_flag++;
	return (0);
}

int	rt_parse_camera(t_element *element)
{
	static int	camera_flag;

	if (element == NULL)
		return (1);
	if (camera_flag != 0)
		return (rt_error_write(ERROR_ELEMENT_DUP, element->id_str), 1);
	if (rt_parse_element_argc(element->info) != ARGC_CAMERA)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.camera.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.camera.orien_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->element_type.camera.fov = rt_parse_element_int(element->info[3]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_arr_range(element->element_type.camera.orien_vect, \
			-1, 1, DIMENSION_NUMBER) != 0 || rt_check_int_range(\
				element->element_type.camera.fov, 0, 180) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	camera_flag++;
	return (0);
}

int	rt_parse_light(t_element *element)
{
	static int	light_flag;

	if (element == NULL)
		return (1);
	if (light_flag != 0)
		return (rt_error_write(ERROR_ELEMENT_DUP, element->id_str), 1);
	if (rt_parse_element_argc(element->info) != ARGC_LIGHT)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.light.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->element_type.light.intensity = \
		rt_parse_element_double(element->info[2]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->element_type.light.intensity, \
			INTENSITY_MIN, INTENSITY_MAX) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	light_flag++;
	return (0);
}

int	rt_parse_sphere(t_element *element)
{
	if (element == NULL)
		return (1);
	if (rt_parse_element_argc(element->info) != ARGC_SPHERE)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.sphere.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->element_type.sphere.diameter = \
		rt_parse_element_double(element->info[2]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		element->element_type.sphere.rgb, \
			element->info[3], ",", COLOR_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->element_type.sphere.diameter, \
		0, FLT_MAX) != 0 \
			|| rt_check_int_arr_range(\
			element->element_type.sphere.rgb, \
			RGB_MIN, RGB_MAX, COLOR_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	return (0);
}

int	rt_parse_plane(t_element *element)
{
	if (element == NULL)
		return (1);
	if (rt_parse_element_argc(element->info) != ARGC_PLANE)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.plane.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.plane.norm_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		element->element_type.plane.rgb, \
			element->info[3], ",", COLOR_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_arr_range(\
		element->element_type.plane.norm_vect, -1, 1, DIMENSION_NUMBER) != 0 \
			|| rt_check_int_arr_range(\
			element->element_type.plane.rgb, \
			RGB_MIN, RGB_MAX, COLOR_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	return (0);
}
