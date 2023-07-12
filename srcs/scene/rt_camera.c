/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:39:58 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 08:43:07 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static void	assign_camera_values(\
t_scene_obj *camera, t_tuple coord, t_tuple orien_vect, unsigned int fov)
{
	t_tuple		pl_ctr;
	double		pl_width;
	double		pl_height;

	if (camera == NULL)
		return ;
	camera->data.camera.coord = coord;
	camera->data.camera.orien_vect = \
		rt_tuple_negate(rt_vector_normalize(orien_vect));
	camera->data.camera.fov = fov;
	camera->data.camera.u_vect = \
		rt_vector_normalize(\
		rt_vector_cross(orien_vect, rt_vector_make(0, 1, 0)));
	camera->data.camera.v_vect = rt_vector_make(1, 0, 0);
	if (rt_float_equal(rt_vector_magnitude(camera->data.camera.u_vect), 0) != 1)
		camera->data.camera.v_vect = \
			rt_vector_normalize(\
			rt_vector_cross(camera->data.camera.u_vect, orien_vect));
	pl_width = tan(rt_deg_to_rad(fov) / 2) * 2;
	pl_height = pl_width * (float)WIN_Y / (float)WIN_X;
	pl_ctr = rt_ray_position(rt_ray_make(coord, orien_vect), CAM_DIST);
	camera->data.camera.pl_top_left = rt_tuple_add(pl_ctr, \
		rt_tuple_add(\
			rt_tuple_times(camera->data.camera.v_vect, pl_height / 2), \
			rt_tuple_times(camera->data.camera.u_vect, -(pl_width / 2))));
	camera->data.camera.t_per_px = pl_width / WIN_X;
}

/* fov is asking for the horizontal field of view as specified by the subject!
** check the <<fundamentals of computer graphics>> book
** here's how you find the img_pl's horizontal value in world space units
**
** http://web.cse.ohio-state.edu/~parent.1/
** classes/681/Lectures/08.RTgeometryHO.pdf
**
*/
t_scene_obj	*rt_camera_make(\
t_tuple coord, t_tuple orien_vect, unsigned int fov)
{
	t_scene_obj	*camera;

	if (fov == 0 || fov >= FOV_MAX)
		return (rt_error_write(ERROR_CAM_MAKE, NULL), NULL);
	camera = rt_scene_obj_make(OBJ_T_CAMERA);
	if (camera == NULL)
		return (NULL);
	assign_camera_values(camera, coord, orien_vect, fov);
	return (camera);
}
