/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:10:37 by jyao              #+#    #+#             */
/*   Updated: 2023/05/31 10:32:28 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	render_mlx_init(t_minirt *minirt)
{
	if (minirt == NULL)
		return (1);
	minirt->mlx_struct.init = mlx_init();
	if (minirt->mlx_struct.init == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	rt_error_write("HEY!\n", NULL);
	minirt->mlx_struct.window = \
		mlx_new_window(minirt->mlx_struct.init, WIN_X, WIN_Y, WIN_NAME);
	if (minirt->mlx_struct.window == NULL)
		return (rt_error_write(ERROR_MLX_INIT, NULL), 1);
	minirt->mlx_struct.canvas = \
		rt_img_make(minirt->mlx_struct.init, WIN_X, WIN_Y);
	return (0);
}

static t_ray	get_ray_at(\
t_scene_obj *camera, int pixel_x, int pixel_y)
{
	t_ray	ray;
	t_tuple	ray_pl_origin;
	double	t_val_x;
	double	t_val_y;

	t_val_x = pixel_x * camera->data.camera.t_per_px + 0.5;
	t_val_y = -(pixel_y * camera->data.camera.t_per_px + 0.5);
	ray_pl_origin = \
		rt_tuple_add(camera->data.camera.pl_top_left, \
			rt_tuple_add(\
				rt_tuple_times(camera->data.camera.u_vect, t_val_x), \
				rt_tuple_times(camera->data.camera.v_vect, t_val_y)));
	ray.direction = rt_tuple_minus(ray_pl_origin, camera->data.camera.coord);
	ray.origin = camera->data.camera.coord;
	return (ray);
}

static void	paint_test(t_minirt *minirt, t_scene *scene)
{
	t_interx	*interx_tmp;
	t_ray		tmp_ray;
	int			i;
	int			j;

	minirt->camera = \
		rt_camera_make(rt_point_make(0, 0, 0), rt_vector_make(0, 0, -1), 90);
	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			tmp_ray = get_ray_at(minirt->camera, j, i);
			interx_tmp = rt_ray_intersect(tmp_ray, scene->shapes[0]);
			if (interx_tmp != NULL && rt_intersect_hit(interx_tmp)->t_val >= 0)
				rt_img_edit_pixel(minirt->mlx_struct.canvas, COLOR_RED, j, i);
			rt_free_intersections(interx_tmp);
			j++;
		}
		i++;
	}
}

int	rt_render(t_minirt	*minirt)
{
	t_mlx_struct	mlx;

	if (minirt == NULL)
		return (1);
	render_mlx_init(minirt);
	mlx = minirt->mlx_struct;
	paint_test(minirt, minirt->scene);
	mlx_put_image_to_window(mlx.init, mlx.window, mlx.canvas->img_mlx, 0, 0);
	mlx_loop(minirt->mlx_struct.init);
	return (0);
}