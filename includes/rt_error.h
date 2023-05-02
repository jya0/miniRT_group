/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/02 13:27:59 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERROR_DIVISOR "error: invalid divisor of zero"
# define ERROR_NOT_VECTOR "error: the argument is not a vector"


int			rt_error_write(char const *msg);


#endif