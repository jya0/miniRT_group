/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:59:23 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 10:42:06 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define _USE_MATH_DEFINES
# define FP_FAST_FMA
# define FP_FAST_FMAF
# define FP_FAST_FMAL

# include	<unistd.h>
# include	<stdlib.h>
# include	<errno.h>
# include	<string.h>
# include	<math.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<stdint.h>
# include	<float.h>
# include	"libft.h"
# include	"mlx.h"
# include	"rt_color.h"
# include	"rt_error.h"
# include	"rt_event.h"
# include	"rt_exit.h"
# include	"rt_float.h"
# include	"rt_geometry.h"
# include	"rt_matrix.h"
# include	"rt_parse.h"
# include	"rt_ray.h"
# include	"rt_render.h"
# include	"rt_scene.h"
# include	"rt_test.h"
# include	"rt_tuple.h"

typedef struct s_minirt {
	t_element		*head_element;
	t_mlx_struct	mlx_struct;
	t_scene			*scene;
}	t_minirt;

#endif