/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:49:49 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 17:17:02 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

typedef struct s_tuple	t_tuple;

void			rt_tuple_print(t_tuple	tuple);

void			rt_file_print(t_element *head_element);

t_matrix		*rt_matrix_print(t_matrix *mtx);

void			rt_interx_list_print(t_interx *head);

/* main_tests.c */
void			test_tuple(void);

void			test_intersections(void);

void			test_matrix_scale(void);

void			test_matrix_translate(void);

void			test_matrix_inverse(void);

void			test_matrix_maths(void);

void			test_matrix_rotate(void);

void			test_matrix_sheer(void);

void			test_fma_speed(void);

#endif