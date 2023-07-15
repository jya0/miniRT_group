/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:42 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 13:42:52 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERROR_MEM_ALLOC		"Error\n failed to allocate memory"
# define ERROR_DIVISOR			"Error\n invalid divisor of zero"

/* tuple */
# define ERROR_NOT_VECTOR		"Error\n the argument is not a vector"
# define ERROR_NOT_POINT		"Error\n the argument is not a point"
# define ERROR_PARALLEL_VEC		"Error\n parallel vectors!"

/* parse */
# define ERROR_WRONG_ARGC		"Error\n wrong argc count"
# define ERROR_FILE_OPEN		"Error\n can't open file: "
# define ERROR_FILE_NAME		"Error\n file has wrong name: "
# define ERROR_FILE_FORMAT		"Error\n file has wrong format: "
# define ERROR_ELEMENT_FORMAT	"Error\n element has wrong format: "
# define ERROR_ELEMENT_RANGE	"Error\n element has wrong value range: "
# define ERROR_ELEMENT_DUP		"Error\n element has duplicate: "
# define ERROR_NOT_NORMALIZE	"Error\n input vector is not normalized: "

/* matrix */
# define ERROR_MATRIX_FORMAT	"Error\n wrong matrix format"
# define ERROR_MATRIX_ASSIGN	"Error\n can't assign matrix"
# define ERROR_MATRIX_READ		"Error\n can't read matrix"
# define ERROR_MATRIX_IDENTITY	"Error\n can't make identity matrix"
# define ERROR_MATRIX_SUBMATRIX	"Error\n can't make submatrix"
# define ERROR_MATRIX_DETERMI	"Error\n can't find determinant"
# define ERROR_MATRIX_MINOR		"Error\n can't find minor"
# define ERROR_MATRIX_COFACTOR	"Error\n can't find cofactor"
# define ERROR_MATRIX_INVERSE	"Error\n can't find inverse"
# define ERROR_MATRIX_TUPLE		"Error\n can't convert matrix to tuple"

/* geometry */
# define ERROR_SHAPE_LIMIT		"Error\n reached shape spawning limit"
# define ERROR_SPHERE_PARAM		"Error\n invalid sphere parameters"
# define ERROR_SHAPE_TRANSFORM	"Error\n transform matrix assignment"
# define ERROR_SPHERE_MAKE		"Error\n can't make sphere"
# define ERROR_PLANE_MAKE		"Error\n can't make plane"
# define ERROR_CYLINDER_MAKE	"Error\n can't make cylinder"

/* ray */
# define ERROR_INTERX_MAKE		"Error\n can't make intersection struct"
# define ERROR_INTERX_LIST		"Error\n can't make intersection list"
# define ERROR_INTERX_ADD		"Error\n can't add the intersection to the list"
# define ERROR_INTERX_SORT		"Error\n can't solve intersection list"
# define ERROR_RAY_TRANSFORM	"Error\n can't transform ray"

/* render */
# define ERROR_CAM_MAKE			"Error\n can't make camera"
# define ERROR_IMG_MAKE			"Error\n can't make mlx img"
# define ERROR_RENDER_INIT		"Error\n can't init render"

/* mlx */
# define ERROR_MLX_INIT			"Error\n failed to initialise mlx"

/* scene */
# define ERROR_SCENE_MAKE		"Error\n can't make scene"
# define ERROR_ELM_OVERFLOW		"Error\n elements loading overflow"
# define ERROR_LOAD_CAM			"Error\n can't load camera"
# define ERROR_LOAD_AMBIENT		"Error\n can't load ambient"
# define ERROR_LOAD_LIGHT		"Error\n can't load light"
# define ERROR_LOAD_SPHERE		"Error\n can't load sphere"
# define ERROR_LOAD_PLANE		"Error\n can't load plane"
# define ERROR_LOAD_CYLINDER	"Error\n can't load cylinder"
# define ERROR_LOAD_ACL			"Error\n can't load A/C/L"

int			rt_error_write(char const *msg, char const *arg);

#endif