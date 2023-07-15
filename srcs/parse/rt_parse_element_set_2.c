/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_element_set_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:24 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 21:27:19 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

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

static int	plane_check_range(t_element *plane)
{
	if (plane == NULL)
		return (1);
	if (rt_check_double_arr_range(\
		plane->data.plane.norm_vect, -1, 1, DIMENSION_NUMBER) != 0 \
			|| rt_check_int_arr_range(\
			&plane->data.plane.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, plane->id_str), 1);
/* 	if (rt_float_equal(rt_vector_magnitude(\
			rt_vector_make(plane->data.plane.norm_vect[0], \
				plane->data.plane.norm_vect[1], \
				plane->data.plane.norm_vect[2])), 1) != 1)
		return (rt_error_write(ERROR_NOT_NORMALIZE, plane->id_str), 1); */
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
	return (plane_check_range(element));
}

static int	cylinder_check_range(t_element *cylinder)
{
	if (cylinder == NULL)
		return (1);
	if (rt_check_double_arr_range(\
		cylinder->data.cylinder.norm_vect, -1, 1, DIMENSION_NUMBER) != 0 \
			|| rt_check_int_arr_range(\
			&cylinder->data.cylinder.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0 \
				|| rt_check_double_range(\
				cylinder->data.cylinder.diameter, \
				0, FLT_MAX) != 0 \
					|| rt_check_double_range(\
					cylinder->data.cylinder.height, \
					0, FLT_MAX) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, cylinder->id_str), 1);
/* 	if (rt_float_equal(rt_vector_magnitude(\
			rt_vector_make(cylinder->data.cylinder.norm_vect[0], \
				cylinder->data.cylinder.norm_vect[1], \
				cylinder->data.cylinder.norm_vect[2])), 1) != 1)
		return (rt_error_write(ERROR_NOT_NORMALIZE, cylinder->id_str), 1); */
	return (0);
}

int	rt_parse_cylinder(t_element *element)
{
	if (element == NULL)
		return (1);
	if (rt_parse_element_argc(element->info) != ARGC_CYLINDER)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->data.cylinder.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->data.cylinder.norm_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data.cylinder.diameter = \
		rt_parse_element_double(element->info[3]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->data.cylinder.height = \
		rt_parse_element_double(element->info[4]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->data.cylinder.trgb[RED], \
			element->info[5], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	return (cylinder_check_range(element));
}
