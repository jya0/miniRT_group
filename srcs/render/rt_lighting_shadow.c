/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lighting_shadow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:28:01 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 15:40:37 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_lighting_shadow(t_scene *scene, t_tuple over_point)
{
	t_tuple				interx_p_to_light;
	double				distance;
	t_ray				shadow_ray;
	t_interx			*i_list;
	t_interx			*i_hit;

	interx_p_to_light = \
		rt_tuple_minus(scene->light->data.light.coord, over_point);
	distance = rt_vector_magnitude(interx_p_to_light);
	shadow_ray.direction = rt_vector_normalize(interx_p_to_light);
	shadow_ray.origin = over_point;
	i_list = rt_scene_intersect(scene, shadow_ray);
	i_hit = rt_intersect_hit(i_list);
	if (i_hit != NULL && rt_float_smaller_equal(i_hit->t_val, distance))
		distance = 1;
	else
		distance = 0;
	rt_free_intersections(i_list);
	return (distance);
}
