/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:36:03 by jyao              #+#    #+#             */
/*   Updated: 2023/05/10 12:19:51 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# include	"minirt.h"

# define BUFFER_SIZE				42
# define RT_FILE_SUFFIX				".rt"
# define SPACE_CHARSET				"\n\t \v\f\r"
# define RT_SUPPORTED_ELEMENTS		"A C L sp pl cy"
# define DIMENSION_NUMBER			3
# define RT_ATOI_FAIL_FLAG			"RT_ATOI_FAIL_FLAG"

/*element ranges*/
# define INTENSITY_MIN				0.0f
# define INTENSITY_MAX				1.0f
# define TRGB_MIN					0
# define TRGB_MAX					255
# define FOV_MIN					0
# define FOV_MAX					180

enum e_element_argc {
	ARGC_AMBIENT	=	3,
	ARGC_CAMERA		=	4,
	ARGC_LIGHT		=	3,
	ARGC_SPHERE		=	4,
	ARGC_PLANE		=	4,
	ARGC_CYLINDER	=	6
};

enum e_trgb {
	TRSPT,
	RED,
	GREEN,
	BLUE,
	TRGB_COUNT
};

typedef struct s_element {
	char				**info;
	char				*id_str;
	union u_element_type {
		struct s_ambient {
			double	intensity;
			int		trgb[TRGB_COUNT];
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
			int		trgb[TRGB_COUNT];
		}			sphere;
		struct s_plane {
			double	coord[DIMENSION_NUMBER];
			double	norm_vect[DIMENSION_NUMBER];
			int		trgb[TRGB_COUNT];
		}			plane;
		struct s_cylinder {
			double	coord[DIMENSION_NUMBER];
			double	norm_vect[DIMENSION_NUMBER];
			double	diameter;
			double	height;
			int		trgb[TRGB_COUNT];
		}			cylinder;
	}					element_type;
	struct s_element	*next;
}				t_element;

typedef int		(*t_parse_fun)(t_element *element);

char			*rt_gnl(int fd);

char			**rt_split(char const *s, char *charset);

int				rt_is_str_digit(char const *str);

int				rt_atoi(const char *str);

t_element		*rt_parse_load(char *rt_file);

int				rt_check_int_arr_range(\
					int *arr, int min, int max, int arr_size);

int				rt_check_int_range(int int_val, int min, int max);

int				rt_check_double_arr_range(\
					double *arr, double min, double max, int arr_size);

int				rt_check_double_range(\
					double double_val, double min, double max);

int				rt_parse_check(t_element *head_element);

double			rt_parse_element_double(char *arg);

int				rt_parse_element_double_arr(\
					double *arr, char *arg, char *delim, int expected_arr_size);

int				rt_parse_element_int(char *arg);

int				rt_parse_element_int_arr(\
					int *arr, char *arg, char *delim, int expected_arr_size);

int				rt_parse_element_argc(char **info);

int				rt_parse_ambient(t_element *element);

int				rt_parse_camera(t_element *element);

int				rt_parse_light(t_element *element);

int				rt_parse_sphere(t_element *element);

int				rt_parse_plane(t_element *element);

int				rt_parse_cylinder(t_element *element);

void			rt_parse(t_minirt *minirt, char *rt_file);

#endif