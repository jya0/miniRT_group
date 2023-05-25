/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:31:50 by jyao              #+#    #+#             */
/*   Updated: 2023/05/25 12:39:18 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# define WIN_SIZE_X	1280
# define WIN_SIZE_Y	720
# define WIN_NAME	"MINIRT: OOO SHINY!"

typedef struct s_minirt	t_minirt;

typedef struct s_mlx_struct {
	void	*init;
	void	*window;
	void	*img_canvas;
}				t_mlx_struct;

typedef enum e_scene_obj_type	{
	TYPE_INIT,
	TYPE_CAMERA,
	TYPE_AMBIENT,
	TYPE_LIGHT
}	t_scene_obj_type;

typedef struct s_scene_obj {
	
	union u_obj_data {
		struct s_camera_obj {
			t_tuple	coord;
			t_tuple	orien_vect;
			int		fov;
			double	cam_dist;
			double	cam_top;
			double	cam_right;
		}	camera;
	}	data_type;
}	t_scene_obj;

int	rt_render(t_minirt	*minirt);

#endif