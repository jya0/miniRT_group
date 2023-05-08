/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:36:03 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 18:34:43 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# include	"minirt.h"

# define BUFFER_SIZE				42
# define RT_FILE_SUFFIX				".rt"
# define RT_SUPPORTED_ELEMENTS		"A C L sp pl cy"
# define DIMENSION_NUMBER			3
# define COLOR_NUMBER				3

typedef struct s_element {
	char				**info;
	char				*id_str;
	union u_element_type {
		struct s_ambient {
			double	intensity;
			int		rgb[COLOR_NUMBER];
		}			ambient;
		struct s_camera {
			double	coord[DIMENSION_NUMBER];
			double	orien_vect[DIMENSION_NUMBER];
			int		fov;
		}			camera;
		struct s_light {
			double	coord[DIMENSION_NUMBER];
			double	intensity;
		}			light;
		struct s_sphere {
			double	coord[DIMENSION_NUMBER];
			double	diameter;
			int		rgb[COLOR_NUMBER];
		}			sphere;
		struct s_plane {
			double	coord[DIMENSION_NUMBER];
			double	norm_vect[DIMENSION_NUMBER];
		}			plane;
		struct s_cylinder {
			double	coord[DIMENSION_NUMBER];
			double	norm_vect[DIMENSION_NUMBER];
			double	diameter;
			double	height;
			int		rgb[COLOR_NUMBER];
		}			cylinder;
	}					element_type;
	struct s_element	*next;
}				t_element;

typedef int		(*t_parse_fun)(t_element *element);

char			*rt_gnl(int fd);

t_element		*rt_parse_load(char *rt_file);

int				rt_parse_check(t_element *head_element);

double			rt_parse_element_double(char *arg);

int				rt_parse_element_int(char *arg);

int				rt_parse_ambient(t_element *element);

int				rt_parse_camera(t_element *element);

int				rt_parse_light(t_element *element);

int				rt_parse_sphere(t_element *element);

int				rt_parse_plane(t_element *element);

int				rt_parse_cylinder(t_element *element);

void			rt_parse(t_minirt *minirt, char *rt_file);

#endif