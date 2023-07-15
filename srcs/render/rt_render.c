/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:10:37 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 13:23:28 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"minirt.h"

static int	render_init(t_minirt *minirt)
{
	if (minirt == NULL)
		return (1);
	minirt->mlx_struct.init = mlx_init();
	if (minirt->mlx_struct.init == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	minirt->mlx_struct.window = \
		mlx_new_window(minirt->mlx_struct.init, WIN_X, WIN_Y, WIN_NAME);
	if (minirt->mlx_struct.window == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	minirt->mlx_struct.canvas = \
		rt_img_make(minirt->mlx_struct.init, WIN_X, WIN_Y);
	if (rt_scene_load(minirt))
		return (1);
	return (0);
}

static t_ray	get_ray_at(\
t_scene_obj *camera, int pixel_x, int pixel_y)
{
	t_ray	ray;
	double	t_val_x;
	double	t_val_y;

	t_val_x = (pixel_x + 0.5f) * camera->data.camera.t_per_px;
	t_val_y = -(pixel_y + 0.5f) * camera->data.camera.t_per_px;
	ray.direction = rt_tuple_add(rt_vector_make(0, 0, -1), \
		rt_tuple_add(camera->data.camera.pl_top_left, \
			rt_tuple_add(\
				rt_tuple_times(camera->data.camera.u_vect, t_val_x), \
				rt_tuple_times(camera->data.camera.v_vect, t_val_y))));
	ray.direction.w = 0;
	ray.direction = rt_vector_normalize(\
		rt_matrix_times_tuple(camera->inv_mtx, ray.direction));
	ray.origin = rt_matrix_times_tuple(camera->inv_mtx, \
		rt_point_make(0, 0, 0));
	return (ray);
}

static void	make_image(t_mlx_struct *mlx, t_scene *scn)
{
	t_interx	*i_lst;
	t_interx	*i_hit;
	t_ray		cam_ray;
	t_tuple		pix_color;
	int			i[2];

	i[0] = 0;
	while (i[0] < WIN_Y)
	{
		i[1] = 0;
		while (i[1] < WIN_X)
		{
			cam_ray = get_ray_at(scn->camera, i[1], i[0]);
			i_lst = rt_scene_intersect(scn, cam_ray);
			i_hit = rt_intersect_hit(i_lst);
			if (i_hit != NULL && i_hit->t_val >= 0)
			{
				pix_color = rt_lighting(i_hit, scn);
				rt_img_edit_pixel(mlx->canvas, pix_color, i[1], i[0]);
			}
			rt_free_intersections(i_lst);
			i[1]++;
		}
		i[0]++;
	}
}

static int	put_image(t_mlx_struct *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->canvas->img_mlx, 0, 0);
	return (0);
}

int	rt_render(t_minirt	*minirt)
{
	if (minirt == NULL)
		return (1);
	rt_error_write("----TESTING RENDERING----", NULL);
	if (render_init(minirt))
		return (rt_error_write(ERROR_RENDER_INIT, NULL));
	make_image(&minirt->mlx_struct, minirt->scene);
	rt_event(minirt);
	mlx_loop_hook(minirt->mlx_struct.init, put_image, &minirt->mlx_struct);
	mlx_loop(minirt->mlx_struct.init);
	return (0);
}
