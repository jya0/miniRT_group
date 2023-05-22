/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_element_set_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:33 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 14:27:47 by jyao             ###   ########.fr       */
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
	element->data_element.ambient.intensity = \
		rt_parse_element_double(element->info[1]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data_element.ambient.trgb[RED], \
			element->info[2], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->data_element.ambient.intensity, \
		INTENSITY_MIN, INTENSITY_MAX) != 0 \
			|| rt_check_int_arr_range(\
			&element->data_element.ambient.trgb[RED], \
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
		element->data_element.camera.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->data_element.camera.orien_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data_element.camera.fov = rt_parse_element_int(element->info[3]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_arr_range(element->data_element.camera.orien_vect, \
			-1, 1, DIMENSION_NUMBER) != 0 || rt_check_int_range(\
				element->data_element.camera.fov, 0, 180) != 0)
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
		element->data_element.light.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data_element.light.intensity = \
		rt_parse_element_double(element->info[2]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->data_element.light.intensity, \
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
		element->data_element.sphere.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data_element.sphere.diameter = \
		rt_parse_element_double(element->info[2]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data_element.sphere.trgb[RED], \
			element->info[3], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_range(\
		element->data_element.sphere.diameter, \
		0, FLT_MAX) != 0 \
			|| rt_check_int_arr_range(\
			&element->data_element.sphere.trgb[RED], \
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
		element->data_element.plane.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->data_element.plane.norm_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data_element.plane.trgb[RED], \
			element->info[3], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_check_double_arr_range(\
		element->data_element.plane.norm_vect, -1, 1, DIMENSION_NUMBER) != 0 \
			|| rt_check_int_arr_range(\
			&element->data_element.plane.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	return (0);
}
