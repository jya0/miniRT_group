/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:58:48 by jyao              #+#    #+#             */
/*   Updated: 2023/05/15 17:42:57 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	test_tuple(void)
{
	t_tuple	a;
	t_tuple	b;

	a = rt_vector_make(-5, 0, 0);
	b = rt_vector_make(0, 5, 0);
	rt_tuple_print(rt_vector_cross(a, b));
	printf("dot = %f\n", rt_vector_dot(a, b));
	printf("magnitude = %f\n", \
	rt_vector_magnitude(rt_tuple_divide(a, rt_vector_magnitude(a))));
}

static void	test_matrix(void)
{
	t_matrix	*mtx1;
	t_matrix	*mtx2;
	t_matrix	*mtx3;
	t_matrix	*mtx4;
	t_matrix	*mtx5;
	t_matrix	*mtx6;
	t_matrix	*mtx7;
	t_matrix	*mtx8;
	t_coord		start;
	t_coord		end;
	double		arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	double		arr2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};

	mtx1 = rt_matrix_make(3, 3);
	rt_matrix_fill(mtx1, arr1, 9);
	rt_matrix_print(mtx1);
	rt_matrix_transpose(mtx1);
	rt_matrix_print(mtx1);
	mtx2 = rt_matrix_make(3, 3);
	rt_matrix_fill(mtx2, arr1, 9);
	rt_matrix_print(mtx2);
	printf("\n|rt_matrix_equal = %d|\n", rt_matrix_equal(mtx1, mtx2));
	rt_matrix_fill(mtx2, arr2, 9);
	rt_matrix_print(mtx2);
	printf("\n|rt_matrix_equal = %d|\n", rt_matrix_equal(mtx1, mtx2));
	mtx3 = rt_matrix_times_matrix(mtx1, mtx2);
	rt_matrix_print(mtx3);
	mtx4 = rt_matrix_make(2, 2);
	rt_matrix_fill(mtx4, arr1, 4);
	rt_matrix_print(mtx4);
	printf("\n|rt_matrix_equal = %d|\n", rt_matrix_equal(mtx3, mtx4));
	mtx5 = rt_matrix_get_identity(mtx1);
	rt_matrix_print(mtx5);
	rt_matrix_print(rt_matrix_transpose(mtx5));
	start = (t_coord){0};
	end = (t_coord){.row = 1, .column = 2};
	mtx6 = rt_matrix_clone(mtx1, start, end);
	rt_matrix_print(mtx6);
	printf("\n|determinant = %f|\n", rt_matrix_determinant_2x2(mtx6));
	mtx7 = rt_matrix_submatrix(mtx1, 0, 1);
	printf("\n|minor = %f|\n", rt_matrix_minor_3x3(mtx1, 2, 2));
	rt_matrix_print(mtx7);
	mtx8 = rt_matrix_cofactor_3x3(mtx1);
	rt_matrix_print(mtx8);
	rt_free_matrix(mtx1);
	rt_free_matrix(mtx2);
	rt_free_matrix(mtx3);
	rt_free_matrix(mtx4);
	rt_free_matrix(mtx5);
	rt_free_matrix(mtx6);
	rt_free_matrix(mtx7);
	rt_free_matrix(mtx8);
}

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	if (argc != 2)
		rt_error_write(ERROR_WRONG_ARGC, NULL);
	else
	{
		minirt = (t_minirt){0};
		rt_parse(&minirt, argv[1]);
		rt_render(&minirt);
		test_tuple();
		test_matrix();
		rt_exit(&minirt);
	}
	return (0);
}
