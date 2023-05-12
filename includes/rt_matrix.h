/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/12 15:36:16 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATRIX_H
# define RT_MATRIX_H

# include	"minirt.h"

typedef struct s_matrix {
	unsigned int	row;
	unsigned int	column;
	double			**matrix;
}				t_matrix;

/* rt_matrix_maths.c */
t_matrix		*rt_matrix_times_matrix(t_matrix *mtx1, t_matrix *mtx2);

/* rt_matrix_get.c */
double			*rt_matrix_get_row(t_matrix *mtx, unsigned int row);

double			*rt_matrix_get_column(t_matrix *mtx, unsigned int column);

t_matrix		*rt_matrix_fill(t_matrix *mtx_to_fill, \
					double *num_arr, unsigned int num_count);

/* rt_matrix.c */
void			rt_free_matrix(t_matrix *mtx_to_free);

int				rt_matrix_equal(t_matrix *mtx1, t_matrix *mtx2);

t_matrix		*rt_matrix_make(unsigned int row, unsigned int column);

#endif
