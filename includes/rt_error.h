/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/24 15:25:36 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERROR_MEM_ALLOC		"Error\n failed to allocate memory"
# define ERROR_DIVISOR			"Error\n invalid divisor of zero"

/* tuple */
# define ERROR_NOT_VECTOR		"Error\n the argument is not a vector"
# define ERROR_NOT_POINT		"Error\n the argument is not a point"

/* parse */
# define ERROR_WRONG_ARGC		"Error\n wrong argc count"
# define ERROR_FILE_OPEN		"Error\n can't open file: "
# define ERROR_FILE_NAME		"Error\n file has wrong name: "
# define ERROR_FILE_FORMAT		"Error\n file has wrong format: "
# define ERROR_ELEMENT_FORMAT	"Error\n element has wrong format: "
# define ERROR_ELEMENT_RANGE	"Error\n element has wrong value range: "
# define ERROR_ELEMENT_DUP		"Error\n element has duplicate: "

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

/* ray */
# define ERROR_INTERX_MAKE		"Error\n can't make intersection struct"
# define ERROR_INTERX_LIST		"Error\n can't make intersection list"
# define ERROR_INTERX_ADD		"Error\n can't add the intersection to the list"
# define ERROR_INTERX_SORT		"Error\n can't solve intersection list"
# define ERROR_RAY_TRANSFORM	"Error\n can't transform ray"

/* mlx */
# define ERROR_MLX_INIT			"Error\n failed to initialise mlx"

int			rt_error_write(char const *msg, char const *arg);

#endif