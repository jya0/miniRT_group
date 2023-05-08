/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 12:39:59 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERROR_DIVISOR		"error: invalid divisor of zero"
# define ERROR_NOT_VECTOR	"error: the argument is not a vector"
# define ERROR_NOT_POINT	"error: the argument is not a point"
# define ERROR_WRONG_ARGC	"error: wrong argc count"
# define ERROR_FILE_OPEN	"error: can't open file "
# define ERROR_FILE_NAME	"error: file has wrong name "
# define ERROR_FILE_FORMAT	"error: file has wrong format "

int			rt_error_write(char const *msg, char const *arg);

#endif