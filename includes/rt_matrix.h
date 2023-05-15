/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 17:40:58 by jyao             ###   ########.fr       */
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

typedef struct s_coord {
	unsigned int	row;
	unsigned int	column;
}				t_coord;

/* rt_matrix_times.c */
t_matrix		*rt_matrix_times_matrix(t_matrix *mtx1, t_matrix *mtx2);

t_matrix		*rt_matrix_times(t_matrix *mtx, double scale);

/* rt_matrix_transpose.c */
t_matrix		*rt_matrix_transpose(t_matrix *mtx);

/* rt_matrix_clone.c */
t_matrix		*rt_matrix_clone(\
					t_matrix *mtx, t_coord start, t_coord end);

/* rt_matrix_determinant.c */
double			rt_matrix_determinant_2x2(t_matrix *mtx);

/* rt_matrix_submatrix.c */
t_matrix		*rt_matrix_submatrix(\
					t_matrix *mtx, unsigned int row_rm, unsigned int col_rm);

/* rt_matrix_minor.c */
double			rt_matrix_minor_3x3(\
					t_matrix *mtx, unsigned int row_rm, unsigned int col_rm);

/* rt_matrix_cofactor.c */
t_matrix		*rt_matrix_cofactor_3x3(t_matrix *mtx);

/* rt_matrix_get.c */
double			*rt_matrix_get_row(t_matrix *mtx, unsigned int row);

double			*rt_matrix_get_column(t_matrix *mtx, unsigned int column);

t_matrix		*rt_matrix_fill(t_matrix *mtx_to_fill, \
					double *num_arr, unsigned int num_count);

t_matrix		*rt_matrix_get_identity(t_matrix *mtx);

/* rt_matrix.c */
void			rt_free_matrix(t_matrix *mtx_to_free);

int				rt_matrix_equal(t_matrix *mtx1, t_matrix *mtx2);

t_matrix		*rt_matrix_make(unsigned int row, unsigned int column);

#endif
