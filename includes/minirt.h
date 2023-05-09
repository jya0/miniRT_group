/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:59:23 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 15:47:42 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

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
# include	"rt_error.h"
# include	"rt_exit.h"
# include	"rt_float.h"
# include	"rt_parse.h"
# include	"rt_render.h"
# include	"rt_test.h"
# include	"rt_tuple.h"

/*------------------CUSTOM_TYPE_DECLARATIONS------------------*/

typedef struct s_element	t_element;

typedef struct s_mlx_struct	t_mlx_struct;

typedef struct s_minirt {
	t_element		*head_element;
	t_mlx_struct	mlx_struct;
}	t_minirt;

#endif