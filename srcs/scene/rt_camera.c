/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:39:58 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 17:40:47 by ooutabac         ###   ########.fr       */
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
	camera->data.camera.orien_vect = rt_tuple_negate(\
		rt_vector_normalize(orien_vect));
	camera->data.camera.fov = fov;
	camera->data.camera.u_vect = rt_vector_normalize(\
		rt_vector_cross(orien_vect, rt_vector_make(0, 1, 0)));
	camera->data.camera.v_vect = rt_vector_make(1, 0, 0);
	if (rt_float_equal(rt_vector_magnitude(camera->data.camera.u_vect), 0) != 1)
		camera->data.camera.v_vect = \
			rt_vector_normalize(\
			rt_vector_cross(camera->data.camera.u_vect, orien_vect));
	pl_width = tan(rt_deg_to_rad(fov) / 2) * 2;
	pl_height = pl_width * (float)WIN_Y / (float)WIN_X;
	pl_ctr = rt_point_make(0, 0, -1);
	camera->data.camera.pl_top_left = rt_tuple_add(pl_ctr, \
		rt_tuple_add(\
			rt_tuple_times(camera->data.camera.v_vect, pl_height / 2), \
			rt_tuple_times(camera->data.camera.u_vect, -(pl_width / 2))));
	camera->data.camera.t_per_px = pl_width / WIN_X;
}

static t_matrix	*get_camera_mtx_orien(t_scene_obj *camera)
{
	t_matrix	*mtx;

	mtx = rt_matrix_get_identity(4);
	mtx->matrix[0][0] = camera->data.camera.u_vect.x;
	mtx->matrix[0][1] = camera->data.camera.u_vect.y;
	mtx->matrix[0][2] = camera->data.camera.u_vect.z;
	mtx->matrix[1][0] = camera->data.camera.v_vect.x;
	mtx->matrix[1][1] = camera->data.camera.v_vect.y;
	mtx->matrix[1][2] = camera->data.camera.v_vect.z;
	mtx->matrix[2][0] = camera->data.camera.orien_vect.x;
	mtx->matrix[2][1] = camera->data.camera.orien_vect.y;
	mtx->matrix[2][2] = camera->data.camera.orien_vect.z;
	rt_matrix_print(mtx);
	return (mtx);
}

static t_matrix	*get_camera_transform(t_scene_obj *camera)
{
	t_matrix	*mtx_orien;
	t_matrix	*mtx_translate;
	t_matrix	*transform;

	mtx_orien = get_camera_mtx_orien(camera);
	mtx_translate = rt_matrix_translate(-camera->data.camera.coord.x, \
		-camera->data.camera.coord.y, \
		-camera->data.camera.coord.z);
	transform = rt_matrix_times_matrix_free(mtx_orien, mtx_translate);
	return (transform);
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
	t_matrix	*transform;

	if (fov == 0 || fov >= FOV_MAX)
		return (rt_error_write(ERROR_CAM_MAKE, NULL), NULL);
	camera = rt_scene_obj_make(OBJ_T_CAMERA);
	if (camera == NULL)
		return (NULL);
	assign_camera_values(camera, coord, rt_vector_normalize(orien_vect), fov);
	transform = get_camera_transform(camera);
	rt_scene_obj_transform_set(camera, transform);
	return (camera);
}
