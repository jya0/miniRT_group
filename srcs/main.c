/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:58:48 by jyao              #+#    #+#             */
/*   Updated: 2023/05/16 13:02:30 by jyao             ###   ########.fr       */
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

static void	test_matrix_inverse(void)
{
	t_matrix	*mtx_a;
	t_matrix	*mtx_b;
	t_matrix	*mtx_c;
	t_matrix	*mtx_inv;
	t_matrix	*mtx_ans;
	double		num_arr_1[] = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	double		num_arr_2[] = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5};

	mtx_a = rt_matrix_make(4, 4);
	rt_matrix_fill(mtx_a, num_arr_1, 16);
	rt_matrix_print(mtx_a);
	mtx_b = rt_matrix_make(4, 4);
	rt_matrix_fill(mtx_b, num_arr_2, 16);
	mtx_c = rt_matrix_times_matrix(mtx_a, mtx_b);
	rt_matrix_print(mtx_c);
	mtx_inv = rt_matrix_inverse(mtx_b);
	mtx_ans = rt_matrix_times_matrix(mtx_c, mtx_inv);
	rt_matrix_print(mtx_ans);
	rt_free_matrix(mtx_a);
	rt_free_matrix(mtx_b);
	rt_free_matrix(mtx_c);
	rt_free_matrix(mtx_inv);
	rt_free_matrix(mtx_ans);
}

static void	test_matrix(void)
{
	t_matrix	*mtx1;
	t_matrix	*mtx2;
	t_matrix	*mtx_times_test;
	t_matrix	*mtx4;
	t_matrix	*mtx_id_test;
	t_matrix	*mtx_clone_test;
	t_matrix	*mtx_sub_test;
	t_matrix	*mtx_det_test;
	t_matrix	*mtx_4x4;
	t_matrix	*mtx_inv_test;
	t_coord		start;
	t_coord		end;
	double		arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	double		arr2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
	double		arr3[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9, -2, -8, 3, 5, -3, 1, 7, 3, 1};
	double		arr4[] = {-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};

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
	mtx_times_test = rt_matrix_times_matrix(mtx1, mtx2);
	rt_matrix_print(mtx_times_test);
	mtx4 = rt_matrix_make(2, 2);
	rt_matrix_fill(mtx4, arr1, 4);
	rt_matrix_print(mtx4);
	printf("\n|rt_matrix_equal = %d|\n", rt_matrix_equal(mtx_times_test, mtx4));
	mtx_id_test = rt_matrix_get_identity(mtx1);
	rt_matrix_print(mtx_id_test);
	rt_matrix_print(rt_matrix_transpose(mtx_id_test));
	start = (t_coord){0};
	end = (t_coord){.row = 1, .column = 2};
	mtx_clone_test = rt_matrix_clone(mtx1, start, end);
	rt_matrix_print(mtx_clone_test);
	printf("\n|determinant = %f|\n", rt_matrix_detmnt_2x2(mtx_clone_test));
	mtx_sub_test = rt_matrix_submatrix(mtx1, 0, 1);
	rt_matrix_print(mtx_sub_test);
	printf("\n|minor = %f|\n", rt_matrix_minor_3x3(mtx1, 2, 2));
	mtx_det_test = rt_matrix_make(5, 5);
	rt_matrix_fill(mtx_det_test, arr3, 25);
	rt_matrix_print(mtx_det_test);
	printf("\n|det = %f|\n", rt_matrix_detmnt(mtx_det_test));
	mtx_4x4 = rt_matrix_make(4, 4);
	rt_matrix_fill(mtx_4x4, arr4, 16);
	mtx_inv_test = rt_matrix_inverse(mtx_4x4);
	rt_matrix_print(mtx_inv_test);
	rt_free_matrix(mtx1);
	rt_free_matrix(mtx2);
	rt_free_matrix(mtx_times_test);
	rt_free_matrix(mtx4);
	rt_free_matrix(mtx_id_test);
	rt_free_matrix(mtx_clone_test);
	rt_free_matrix(mtx_sub_test);
	rt_free_matrix(mtx_det_test);
	rt_free_matrix(mtx_4x4);
	rt_free_matrix(mtx_inv_test);
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
		test_matrix_inverse();
		rt_exit(&minirt);
	}
	return (0);
}
