/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_geometry.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:05:26 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 17:05:57 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_GEOMETRY_H
# define RT_GEOMETRY_H

# include	"rt_tuple.h"
# include	"rt_parse.h"

typedef enum e_shape_type {
	TYPE_INIT,
	TYPE_SPHERE,
	TYPE_PLANE,
	TYPE_CYLINDER
}	t_shape_type;

typedef struct s_shape {
	size_t				id;
	t_shape_type		shape_type;
	t_tuple				origin;
	int					trgb[TRGB_COUNT];
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
	}					data_shape;
}	t_shape;

t_shape		*rt_sphere_make(double diameter);

t_shape		*rt_plane_make(t_tuple norm_vector);

t_shape		*rt_cylinder_make(\
				double diameter, double height, t_tuple norm_vector);

t_shape		*rt_shape_info_fill(t_shape *shape, t_tuple origin, int *trgb);

t_shape		*rt_shape_make(void);

void		rt_free_shape(t_shape *shape);

#endif