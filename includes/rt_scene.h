/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:01:15 by jyao              #+#    #+#             */
/*   Updated: 2023/05/31 09:41:21 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

# include	"rt_tuple.h"
# include	"rt_geometry.h"

typedef enum e_scene_obj_type {
	OBJ_T_INIT,
	OBJ_T_CAMERA,
	OBJ_T_AMBIENT,
	OBJ_T_LIGHT
}	t_scene_obj_type;

typedef struct s_scene_obj {
	t_scene_obj_type	type;
	union u_data_obj {
		struct s_camera_obj {
			t_tuple	coord;
			t_tuple	orien_vect;
			int		fov;
			t_tuple	u_vect;
			t_tuple	v_vect;
			t_tuple	pl_top_left;
			double	t_per_px;
		}	camera;
	}	data;
}	t_scene_obj;

typedef struct s_scene {
	unsigned int	shapes_count;
	unsigned int	objs_count;
	unsigned int	shapes_total;
	unsigned int	objs_total;
	t_shape			**shapes;
	t_scene_obj		**scene_objs;
}	t_scene;

typedef int (*t_load_fun)(t_minirt *, t_element *);

/* rt_scene_obj.c */
t_scene_obj		*rt_scene_obj_make(t_scene_obj_type type);

void			rt_free_scene_obj(t_scene_obj *scene_obj);

t_scene_obj		*rt_camera_make(\
	t_tuple coord, t_tuple orien_vect, unsigned int fov);

/* rt_scene.c */
t_scene			*rt_scene_make(\
	unsigned int shapes_total, unsigned int objs_total);

/* rt_scene_load.c */
int				rt_scene_load(t_minirt *minirt);

/* rt_scene_load_set_1.c */
int				rt_load_ambient(t_minirt *minirt, t_element *element);

int				rt_load_camera(t_minirt *minirt, t_element *element);

int				rt_load_light(t_minirt *minirt, t_element *element);

int				rt_load_sphere(t_minirt *minirt, t_element *element);

int				rt_load_plane(t_minirt *minirt, t_element *element);

int				rt_load_cylinder(t_minirt *minirt, t_element *element);

#endif
