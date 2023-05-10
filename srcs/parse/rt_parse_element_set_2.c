/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_element_set_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:24 by jyao              #+#    #+#             */
/*   Updated: 2023/05/10 12:19:51 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	cylinder_check_range(t_element *element)
{
	if (element == NULL)
		return (1);
	if (rt_check_double_arr_range(\
		element->element_type.cylinder.norm_vect, -1, 1, DIMENSION_NUMBER) != 0 \
			|| rt_check_int_arr_range(\
			&element->element_type.cylinder.trgb[RED], \
			TRGB_MIN, TRGB_MAX, TRGB_COUNT - 1) != 0 \
				|| rt_check_double_range(\
				element->element_type.cylinder.diameter, \
				0, FLT_MAX) != 0 \
					|| rt_check_double_range(\
					element->element_type.cylinder.height, \
					0, FLT_MAX) != 0)
		return (rt_error_write(ERROR_ELEMENT_RANGE, element->id_str), 1);
	return (0);
}

int	rt_parse_cylinder(t_element *element)
{
	if (element == NULL)
		return (1);
	if (rt_parse_element_argc(element->info) != ARGC_CYLINDER)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.cylinder.coord, \
			element->info[1], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_double_arr(\
		element->element_type.cylinder.norm_vect, \
			element->info[2], ",", DIMENSION_NUMBER) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->element_type.cylinder.diameter = \
		rt_parse_element_double(element->info[3]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	element->element_type.cylinder.height = \
		rt_parse_element_double(element->info[4]);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	if (rt_parse_element_int_arr(\
		&element->element_type.cylinder.trgb[RED], \
			element->info[5], ",", TRGB_COUNT - 1) != 0)
		return (rt_error_write(ERROR_ELEMENT_FORMAT, element->id_str), 1);
	return (cylinder_check_range(element));
}
