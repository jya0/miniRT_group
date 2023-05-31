/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_element_set_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:33 by jyao              #+#    #+#             */
/*   Updated: 2023/05/30 12:07:28 by jyao             ###   ########.fr       */
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
	element->data.ambient.intensity = \
		rt_parse_element_double(element->info[1]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data.ambient.trgb[RED], \
			element->info[2], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->data.ambient.intensity, \
		INTENSITY_MIN, INTENSITY_MAX) != 0 \
			|| rt_check_int_arr_range(\
			&element->data.ambient.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0)
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
		element->data.camera.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->data.camera.orien_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data.camera.fov = rt_parse_element_int(element->info[3]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_arr_range(element->data.camera.orien_vect, \
			-1, 1, DIMENSION_NUMBER) != 0 || rt_check_int_range(\
				element->data.camera.fov, 0, 180) != 0)
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
		element->data.light.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data.light.intensity = \
		rt_parse_element_double(element->info[2]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->data.light.intensity, \
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
		element->data.sphere.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data.sphere.diameter = \
		rt_parse_element_double(element->info[2]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data.sphere.trgb[RED], \
			element->info[3], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->data.sphere.diameter, \
		0, FLT_MAX) != 0 \
			|| rt_check_int_arr_range(\
			&element->data.sphere.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0)
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
		element->data.plane.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->data.plane.norm_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data.plane.trgb[RED], \
			element->info[3], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_arr_range(\
		element->data.plane.norm_vect, -1, 1, DIMENSION_NUMBER) != 0 \
			|| rt_check_int_arr_range(\
			&element->data.plane.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	return (0);
}
