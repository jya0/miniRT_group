/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:49:49 by jyao              #+#    #+#             */
/*   Updated: 2023/05/12 15:32:12 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

# include	"minirt.h"

typedef struct s_tuple	t_tuple;

void			rt_tuple_print(t_tuple	tuple);

void			rt_file_print(t_element *head_element);

t_matrix		*rt_matrix_print(t_matrix *mtx);

#endif