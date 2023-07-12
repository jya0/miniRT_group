/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:01:15 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 13:11:12 by jyao             ###   ########.fr       */
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
	t_matrix			*mtx_transform;
	t_matrix			*inv_mtx;
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
		struct s_light_obj {
			t_tuple	coord;
			double	intensity;
		}	light;
		struct s_ambient_obj {
			t_tuple	color;
			double	intensity;
		}	ambient;
	}	data;
}	t_scene_obj;

typedef struct s_scene {
	unsigned int	shapes_count;
	unsigned int	objs_count;
	unsigned int	shapes_total;
	unsigned int	objs_total;
	t_shape			**shapes;
	t_scene_obj		**objs;
	t_scene_obj		*camera;
	t_scene_obj		*ambient;
	t_scene_obj		*light;
}	t_scene;

typedef int (*t_load_fun)(t_scene *, t_element *);

/* rt_scene_obj.c */
t_scene_obj		*rt_scene_obj_make(t_scene_obj_type type);

t_scene_obj		*rt_scene_obj_transform_set(\
	t_scene_obj *scene_obj, t_matrix *mtx_transform);

void			rt_free_scene_obj(t_scene_obj *scene_obj);

t_scene_obj		*rt_camera_make(\
	t_tuple coord, t_tuple orien_vect, unsigned int fov);

t_scene_obj		*rt_light_make(t_tuple coord, double intensity);

t_scene_obj		*rt_ambient_make(t_tuple color, double intensity);

/* rt_scene.c */
t_scene			*rt_scene_make(\
	unsigned int shapes_total);

void			rt_free_scene(t_scene *scene);

/* rt_scene_load.c */
int				rt_scene_load(t_minirt *minirt);

/* rt_scene_load_set_1.c */
int				rt_load_ambient(t_scene *scene, t_element *element);

int				rt_load_camera(t_scene *scene, t_element *element);

int				rt_load_light(t_scene *scene, t_element *element);

int				rt_load_sphere(t_scene *scene, t_element *element);

int				rt_load_plane(t_scene *scene, t_element *element);

int				rt_load_cylinder(t_scene *scene, t_element *element);

/* rt_scene_intersect.c */
t_interx		*rt_scene_intersect(t_scene *scene, t_ray ray);

#endif
