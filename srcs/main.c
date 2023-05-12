/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:58:48 by jyao              #+#    #+#             */
/*   Updated: 2023/05/12 16:43:02 by jyao             ###   ########.fr       */
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
	double		arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	double		arr2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};

	mtx1 = rt_matrix_make(3, 3);
	rt_matrix_fill(mtx1, arr1, 9);
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
	rt_free_matrix(mtx1);
	rt_free_matrix(mtx2);
	rt_free_matrix(mtx3);
	rt_free_matrix(mtx4);
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
