/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:42 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 14:22:17 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATRIX_H
# define RT_MATRIX_H

typedef struct s_matrix {
	unsigned int	row;
	unsigned int	column;
	double			**matrix;
}				t_matrix;

typedef struct s_mtx_index {
	unsigned int	row;
	unsigned int	column;
}				t_mtx_index;

/* rt_matrix_times.c */
t_matrix		*rt_matrix_times_matrix(t_matrix *mtx1, t_matrix *mtx2);

t_matrix		*rt_matrix_times(t_matrix *mtx, double scale);

/* rt_matrix_transpose.c */
t_matrix		*rt_matrix_transpose(t_matrix *mtx);

/* rt_matrix_clone.c */
t_matrix		*rt_matrix_clone(\
					t_matrix *mtx, t_mtx_index start, t_mtx_index end);

/* rt_matrix_detmnt.c */
double			rt_matrix_detmnt_2x2(t_matrix *mtx);
double			rt_matrix_detmnt(t_matrix *mtx);

/* rt_matrix_submatrix.c */
t_matrix		*rt_matrix_submatrix(\
					t_matrix *mtx, unsigned int row_rm, unsigned int col_rm);

/* rt_matrix_minor.c */
double			rt_matrix_minor_3x3(\
					t_matrix *mtx, unsigned int row_rm, unsigned int col_rm);

/* rt_matrix_cofactor.c */
t_matrix		*rt_matrix_cofactor(t_matrix *mtx);

/* rt_matrix_inverse.c */
t_matrix		*rt_matrix_inverse(t_matrix *mtx);

/* rt_matrix_get.c */
double			*rt_matrix_get_row(t_matrix *mtx, unsigned int row);

double			*rt_matrix_get_column(t_matrix *mtx, unsigned int column);

t_matrix		*rt_matrix_fill(t_matrix *mtx_to_fill, \
					double *num_arr, unsigned int num_count);

t_matrix		*rt_matrix_get_identity(unsigned int size);

/* rt_matrix_tuple.c */
t_tuple			rt_matrix_to_tuple(t_matrix	*mtx, ssize_t row, ssize_t col);

t_matrix		*rt_tuple_to_matrix(t_tuple tuple);

/* rt_matrix_translate.c */
t_matrix		*rt_matrix_translate(double x, double y, double z);

/* rt_matrix_scale.c */
t_matrix		*rt_matrix_scale(double x, double y, double z);

/* rt_matrix_rotate.c */
t_matrix		*rt_matrix_rotate_x(double radians);

t_matrix		*rt_matrix_rotate_y(double radians);

t_matrix		*rt_matrix_rotate_z(double radians);

/* rt_matrix_sheer.c */
t_matrix		*rt_matrix_sheer(\
					t_tuple x_rela, t_tuple y_rela, t_tuple z_rela);

/* rt_matrix.c */
void			rt_free_matrix(t_matrix *mtx_to_free);

int				rt_matrix_equal(t_matrix *mtx1, t_matrix *mtx2);

t_matrix		*rt_matrix_make(unsigned int row, unsigned int column);

#endif
