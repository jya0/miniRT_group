/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:10:37 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 16:33:18 by jyao             ###   ########.fr       */
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

	t_val_x = (float)(pixel_x + 0.5f) * camera->data.camera.t_per_px;
	t_val_y = -((float)(pixel_y + 0.5f) * camera->data.camera.t_per_px);
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

static void	paint_test(t_minirt *minirt, t_scene *scene)
{
	t_interx	*interx_tmp;
	t_interx	*interx_hit;
	t_ray		tmp_ray;
	t_tuple		pix_color;
	int			i;
	int			j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			tmp_ray = get_ray_at(scene->camera, j, i);
			interx_tmp = rt_scene_intersect(scene, tmp_ray);
			// interx_tmp = rt_ray_intersect(tmp_ray, scene->shapes[0]);
			interx_hit = rt_intersect_hit(interx_tmp);
			if (interx_hit != NULL && interx_hit->t_val >= 0)
			{
				pix_color = rt_lighting(rt_ray_position(interx_hit->ray, interx_hit->t_val), interx_hit, scene);
				rt_img_edit_pixel(minirt->mlx_struct.canvas, \
					rt_color_to_trgb(pix_color), \
					j, i);
			}
			rt_free_intersections(interx_tmp);
			j++;
		}
		i++;
	}
}

static int	test_render(t_mlx_struct *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->canvas->img_mlx, 0, 0);
	mlx_string_put(mlx->init, mlx->window, 50, 50, COLOR_RED, "HELLO THERE!!!");
	return (0);
}

int	rt_render(t_minirt	*minirt)
{
	t_mlx_struct	mlx;

	if (minirt == NULL)
		return (1);
	rt_error_write("----TESTING RENDERING----", NULL);
	if (render_init(minirt))
		return (rt_error_write(ERROR_RENDER_INIT, NULL));
	mlx = minirt->mlx_struct;
	paint_test(minirt, minirt->scene);
	mlx_loop_hook(mlx.init, test_render, &mlx);
	mlx_loop(minirt->mlx_struct.init);
	return (0);
}
