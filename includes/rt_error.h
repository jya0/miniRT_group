/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 19:09:26 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERROR_MEM_ALLOC		"Error\n failed to allocate memory"
# define ERROR_DIVISOR			"Error\n invalid divisor of zero"
# define ERROR_NOT_VECTOR		"Error\n the argument is not a vector"
# define ERROR_NOT_POINT		"Error\n the argument is not a point"
# define ERROR_WRONG_ARGC		"Error\n wrong argc count"
# define ERROR_FILE_OPEN		"Error\n can't open file: "
# define ERROR_FILE_NAME		"Error\n file has wrong name: "
# define ERROR_FILE_FORMAT		"Error\n file has wrong format: "
# define ERROR_ELEMENT_FORMAT	"Error\n element has wrong format: "
# define ERROR_ELEMENT_RANGE	"Error\n element has wrong value range: "
# define ERROR_ELEMENT_DUP		"Error\n element has duplicate: "

int			rt_error_write(char const *msg, char const *arg);

#endif