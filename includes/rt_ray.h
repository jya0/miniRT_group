/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:42:19 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 23:16:28 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2023/07/15 12:57:05 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAY_H
# define RT_RAY_H

# include	"rt_tuple.h"

enum e_solutions_count {
	QUADR_SOL = 2,
	CUBIC_SOL,
	QUART_SOL
};

typedef struct s_ray {
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_interx {
	t_shape			*shape;
	t_ray			ray;
	double			t_val;
	t_tuple			interx_p;
	t_tuple			eye_vect;
	t_tuple			norm_vect;
	t_tuple			over_point;
	unsigned char	inside;
	struct s_interx	*prev;
	struct s_interx	*next;
}	t_interx;

enum e_cylinder_variables {
	CV_A = 0,
	CV_B,
	CV_BA,
	CV_PA,
	CV_OC,
	CVT_COUNT,
	CV_BABA = 0,
	CV_BARD,
	CV_BAOC,
	CV_K2,
	CV_K1,
	CV_K0,
	CV_H,
	CV_T,
	CV_Y,
	CVF_COUNT
};

typedef struct s_variables {
	t_tuple	*tuples;
	double	*floats;
}	t_variables;

/* rt_ray.c */
t_ray		rt_ray_make(t_tuple origin, t_tuple direction);

/* rt_ray_maths.c */
t_tuple		rt_ray_position(t_ray ray, double t);

/* rt_intersect.c */
t_interx	*rt_intersect_make(t_shape *shape, t_ray ray, double t_val);

t_interx	*rt_intersect_hit(t_interx	*head);

/* rt_intersect_list.c */
t_interx	*rt_interx_list_make(\
		unsigned int xcount, double *t_vals, t_shape *shape, t_ray ray);

t_interx	*rt_intersect_add_sort(\
		t_interx **head, t_interx *new_intersect, int (*cmp)(double, double));

void		rt_intersect_sort(t_interx **head, int (*cmp)(double, double));

void		rt_free_intersections(t_interx *head);

void		rt_intersect_add_end(t_interx *list1, t_interx *list2);

/* rt_ray_intersect.c */
t_interx	*rt_ray_intersect(t_ray ray, t_shape *shape);

double		*rt_quadratic_formula(double a, double b, double c);

/* rt_ray_intersect_sphere.c */
t_interx	*rt_ray_intersect_sphere(t_ray ray, t_shape *sphere);

/* rt_ray_intersect_plane.c */
t_interx	*rt_ray_intersect_plane(t_ray ray, t_shape *plane);

/* rt_ray_intersect_cylinder.c */
t_interx	*rt_ray_intersect_cylinder(t_ray ray, t_shape *cylinder);

/* rt_ray_transform.c */
t_ray		rt_ray_transform(t_ray ray, t_matrix *mtx_transform);

/* rt_ray_normal.c */
t_tuple		rt_ray_normal(t_shape *shape, t_tuple w_point);

/* rt_ray_normal_sphere.c */
t_tuple		rt_ray_normal_sphere(t_shape *sphere, t_tuple w_point);

/* rt_ray_normal_plane.c */
t_tuple		rt_ray_normal_plane(t_shape *plane);

/* rt_ray_normal_cylinder.c */
t_tuple		rt_ray_normal_cylinder(t_shape *cylinder, t_tuple w_point);

/* rt_ray_reflect.c */
t_tuple		rt_ray_reflect(t_tuple in_vect, t_tuple norm_vect);

#endif