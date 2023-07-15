/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lighting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:01:44 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 15:45:19 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static t_tuple	get_ambient(\
t_tuple effective_color, t_material material, t_scene_obj *ambient)
{
	t_tuple	amb_eff_color;
	double	amb_intensity;

	amb_intensity = ambient->data.ambient.intensity * material.ambient;
	amb_eff_color = \
		rt_color_times_color(effective_color, ambient->data.ambient.color);
	return (rt_color_times(effective_color, amb_intensity));
}

static t_tuple	get_diffuse(\
t_tuple effective_color, t_material material, double light_dot_norm)
{
	if (!rt_float_bigger_equal(light_dot_norm, 0))
		return (rt_color_make(0, 0, 0, 0));
	return (rt_color_times(effective_color, material.diffuse * light_dot_norm));
}

static t_tuple	get_specular(\
double light_dot_norm, double light_reflect_dot_eye, \
t_material material, double light_intensity)
{
	double	specular_factor;

	if (!rt_float_bigger_equal(light_dot_norm, 0) \
		|| rt_float_smaller_equal(light_reflect_dot_eye, 0))
		return (rt_color_make(0, 0, 0, 0));
	specular_factor = pow(light_reflect_dot_eye, material.shininess);
	return (rt_color_times(rt_color_make(0, 1, 1, 1), \
		light_intensity * material.specular * specular_factor));
}

static t_tuple	get_phong_model_color(\
t_tuple ambient, t_tuple diffuse, t_tuple specular)
{
	return (rt_color_clamp(rt_color_add(ambient, \
			rt_color_add(diffuse, specular))));
}

t_tuple	rt_lighting(t_interx *i_hit, t_scene *scene)
{
	t_tuple	light_vect;
	t_tuple	effective_color;
	double	light_dot_norm;

	if (i_hit == NULL || scene == NULL)
		return (rt_color_make(0, 0, 0, 0));
	effective_color = \
		rt_color_times(i_hit->shape->material.color, \
			scene->light->data.light.intensity);
	light_vect = \
		rt_vector_normalize(\
			rt_tuple_minus(scene->light->data.light.coord, i_hit->interx_p));
	light_dot_norm = rt_vector_dot(light_vect, i_hit->norm_vect);
	if (rt_lighting_shadow(scene, i_hit->over_point))
		return (get_ambient(effective_color, \
			i_hit->shape->material, scene->ambient));
	return (get_phong_model_color(\
		get_ambient(effective_color, i_hit->shape->material, scene->ambient), \
		get_diffuse(effective_color, \
			i_hit->shape->material, light_dot_norm), \
		get_specular(light_dot_norm, \
			rt_vector_dot(\
				rt_ray_reflect(rt_tuple_negate(light_vect), i_hit->norm_vect), \
				i_hit->eye_vect), \
		i_hit->shape->material, scene->light->data.light.intensity)));
}
