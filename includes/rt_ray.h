/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:42:19 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 13:23:13 by ooutabac         ###   ########.fr       */
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
	struct s_interx	*prev;
	struct s_interx	*next;
}	t_interx;

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

/* rt_ray_transform.c */
t_ray		rt_ray_transform(t_ray ray, t_matrix *mtx_transform);

/* rt_ray_normal.c */
t_tuple		rt_ray_normal(t_shape *shape, t_tuple w_point);

/* rt_ray_normal_sphere.c */
t_tuple		rt_ray_normal_sphere(t_shape *sphere, t_tuple w_point);

/* rt_ray_normal_plane.c */
t_tuple		rt_ray_normal_plane(t_shape *plane, t_tuple o_point);

/* rt_ray_reflect.c */
t_tuple		rt_ray_reflect(t_tuple in_vect, t_tuple norm_vect);

#endif