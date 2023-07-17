/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:39:58 by jyao              #+#    #+#             */
/*   Updated: 2023/07/17 19:20:02 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static void	assign_camera_values(\
t_scene_obj *cam, t_tuple coord, t_tuple orien, unsigned int fov)
{
	t_tuple		pl_ctr;
	double		pl_width;
	double		pl_height;

	if (cam == NULL)
		return ;
	cam->data.camera.coord = coord;
	cam->data.camera.orien_vect = rt_tuple_negate(\
		rt_vector_normalize(orien));
	cam->data.camera.fov = fov;
	cam->data.camera.u_vect = rt_vector_cross(orien, rt_vector_make(0, 1, 0));
	cam->data.camera.v_vect = rt_vector_cross(cam->data.camera.u_vect, orien);
	if (rt_vector_magnitude(cam->data.camera.u_vect) == 0)
	{
		cam->data.camera.v_vect = rt_vector_make(0, 0, -1);
		cam->data.camera.u_vect = rt_vector_make(1, 0, 0);
	}
	pl_width = tan(rt_deg_to_rad(fov) / 2) * 2;
	pl_height = pl_width * (float)WIN_Y / (float)WIN_X;
	pl_ctr = rt_ray_position(rt_ray_make(coord, orien), CAM_DIST);
	cam->data.camera.pl_top_left = rt_tuple_add(pl_ctr, rt_tuple_add(\
			rt_tuple_times(cam->data.camera.v_vect, pl_height / 2), \
			rt_tuple_times(cam->data.camera.u_vect, -(pl_width / 2))));
	cam->data.camera.t_per_px = pl_width / WIN_X;
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
t_tuple coord, t_tuple orien, unsigned int fov)
{
	t_scene_obj	*camera;

	if (fov == 0 || fov >= FOV_MAX)
		return (rt_error_write(ERROR_CAM_MAKE, NULL), NULL);
	camera = rt_scene_obj_make(OBJ_T_CAMERA);
	if (camera == NULL)
		return (NULL);
	assign_camera_values(camera, coord, rt_vector_normalize(orien), fov);
	return (camera);
}
