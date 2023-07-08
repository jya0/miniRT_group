/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lighting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:44 by jyao              #+#    #+#             */
/*   Updated: 2023/07/08 17:14:26 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"


static t_tuple norm_rgb(t_tuple color)
{
	float dummy;

	// color = rt_color_times(color, 255);
	dummy = color.y + color.z + color.w;
	color.y = color.y / dummy;
	color.z = color.z / dummy;
	color.w = color.w / dummy;
	return (color);
}
static t_tuple	get_all_color(\
t_tuple surface, t_tuple ambient, t_tuple diffuse, float light_dot_norm)
{
	t_tuple	amb;
	t_tuple	dif;

	amb = norm_rgb(amb);
	dif = rt_tuple_times(diffuse, 255);
	amb = rt_tuple_times(rt_color_times_color(surface, ambient), 0.2);
	dif = rt_tuple_times(rt_color_times_color(surface, diffuse), light_dot_norm);
	if (!rt_float_bigger_equal(light_dot_norm, 0))
		dif = rt_color_make(0, 0, 0, 0);
	return (rt_color_add(amb, dif));
}

static t_tuple	get_ambient(t_tuple effective_color, t_material material)
{
	// rt_tuple_print(rt_color_times(effective_color, material.ambient));
	// rt_error_write("AAAAA\n", NULL);
	return (rt_color_times(effective_color, material.ambient));
}

static t_tuple	get_diffuse(\
t_tuple effective_color, t_material material, double light_dot_norm)
{
	if (!rt_float_bigger_equal(light_dot_norm, 0))
		return (rt_color_make(0, 0, 0, 0));
	// rt_tuple_print(rt_color_times(effective_color, material.diffuse * light_dot_norm));
	// rt_error_write("BBBBBB\n", NULL);
	return (rt_color_times(effective_color, material.diffuse * light_dot_norm));
}

static t_tuple	get_specular(\
double light_dot_norm, double light_reflect_dot_eye, \
t_material material, double light_intensity)
{
	double	specular_factor;

	// printf("\n|light_dot_norm = %f, light_reflect_dot_eye = %f|\n", light_dot_norm, light_reflect_dot_eye);
	if (!rt_float_bigger_equal(light_dot_norm, 0) \
		|| rt_float_smaller_equal(light_reflect_dot_eye, 0))
		return (rt_color_make(0, 0, 0, 0));
	// printf("\n|light_dot_norm = %f, light_reflect_dot_eye = %f|\n", light_dot_norm, light_reflect_dot_eye);
	specular_factor = pow(light_reflect_dot_eye, material.shininess);
	// rt_error_write("CCCCCCC\n", NULL);
	// printf("%f\n", specular_factor);
	// rt_tuple_print(rt_color_times(rt_color_make(0, 1, 1, 1), light_intensity * material.specular * specular_factor));
	return (rt_color_times(rt_color_make(0, 1, 1, 1), \
		light_intensity * material.specular * specular_factor));
}

static t_tuple	get_phong_model_color(\
t_tuple ambient, t_tuple diffuse, t_tuple specular)
{
	return (rt_color_clamp(rt_color_add(ambient, \
			rt_color_add(diffuse, specular))));
}

t_tuple	rt_lighting(\
t_tuple point_of_interx, t_interx *interx_info, t_minirt *minirt)
{
	t_tuple	eye_vect;
	t_tuple	norm_vect;
	t_tuple	light_vect;
	t_tuple	effective_color;
	double	light_dot_norm;

	static int num_theres_light;

	if (interx_info == NULL || minirt == NULL)
		return (printf("\n|num_theres_light = %d|\n", num_theres_light), rt_color_make(0, 0, 0, 0));
	effective_color = \
		rt_color_times(\
			interx_info->shape->material.color, minirt->light->data.light.intensity);
	eye_vect = rt_vector_normalize(rt_tuple_negate(interx_info->ray.direction));
	// rt_tuple_print(interx_info->ray.direction);
	// rt_tuple_print(eye_vect);
	if (!rt_float_smaller_equal(light_dot_norm, 0))
		num_theres_light++;
	norm_vect = rt_ray_normal(interx_info->shape, point_of_interx);
	// rt_tuple_print(norm_vect);
	// return (rt_color_times(effective_color, rt_vector_dot(norm_vect, eye_vect)));
	// rt_tuple_print(norm_vect);
	// printf("_____________________\n");
	// rt_tuple_print(light->data.light.coord);
	// rt_tuple_print(point_of_interx);
	light_vect = \
		rt_vector_normalize(\
		rt_tuple_minus(minirt->light->data.light.coord, point_of_interx));
	// rt_tuple_print(norm_vect);
	// rt_tuple_print(light_vect);
	light_dot_norm = rt_vector_dot(light_vect, norm_vect);
	// return (get_all_color(interx_info->shape->material.color, minirt->ambient->data.ambient.color, rt_color_make(0, 1, 1, 1), light_dot_norm));
	// return (effective_color);
	// return (get_ambient(effective_color, interx_info->shape->material));
	// return (get_diffuse(effective_color, interx_info->shape->material, light_dot_norm));
	/* return (get_specular(light_dot_norm, \
			rt_vector_dot(rt_ray_reflect(rt_tuple_negate(light_vect), \
				norm_vect), eye_vect), \
			interx_info->shape->material, light->data.light.intensity)); */
	return (get_phong_model_color(\
		get_ambient(effective_color, interx_info->shape->material), \
		get_diffuse(effective_color, \
			interx_info->shape->material, light_dot_norm), \
		get_specular(light_dot_norm, \
		rt_vector_dot(rt_ray_reflect(rt_tuple_negate(light_vect), norm_vect), \
			eye_vect), \
		interx_info->shape->material, minirt->light->data.light.intensity)));
}
