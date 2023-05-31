/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_geometry.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:05:26 by jyao              #+#    #+#             */
/*   Updated: 2023/05/31 09:42:29 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_GEOMETRY_H
# define RT_GEOMETRY_H

# include	"rt_tuple.h"
# include	"rt_parse.h"
# include	"rt_matrix.h"

typedef enum e_shape_type {
	SHAPE_T_INIT,
	SHAPE_T_SPHERE,
	SHAPE_T_PLANE,
	SHAPE_T_CYLINDER
}	t_shape_type;

typedef struct s_shape {
	size_t				id;
	t_shape_type		type;
	t_tuple				origin;
	int					trgb[TRGB_COUNT];
	t_matrix			*mtx_transform;
	union u_data_shape {
		struct s_sphere_shape	{
			double	diameter;
			double	radius;
		}		sphere;
		struct s_plane_shape	{
			t_tuple	norm_vector;
		}		plane;
		struct s_cylinder_shape	{
			t_tuple	norm_vector;
			double	diameter;
			double	radius;
			double	height;
		}		cylinder;
	}					data;
}	t_shape;

t_shape		*rt_sphere_make(double diameter);

t_shape		*rt_plane_make(t_tuple norm_vector);

t_shape		*rt_cylinder_make(\
				double diameter, double height, t_tuple norm_vector);

/* rt_shape_transform.c */
t_shape		*rt_shape_transform_set(t_shape *shape, t_matrix *mtx_transform);

/* rt_shape.c */
t_shape		*rt_shape_make(t_shape_type type);

t_shape		*rt_shape_info_fill(t_shape *shape, t_tuple origin, int *trgb);

void		rt_free_shape(t_shape *shape);

#endif