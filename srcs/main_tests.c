/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:19:47 by jyao              #+#    #+#             */
/*   Updated: 2023/06/11 10:49:55 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"
#include	<time.h>

void	test_fma_speed(void)
{
	unsigned int	i;
	clock_t			start, end;
	double			execution_time;

	printf("\n----TESTING FMA SPEED----\n");
	start = clock();
	i = 0;
	while (i < UINT32_MAX / 10)
	{
		i += 1 * 1;
		// i = fma(1, 1, i);
	}
	end = clock();
	execution_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n|%.2f seconds|\n", execution_time);
}

void	test_ray_reflect(void)
{
	t_tuple	in = rt_vector_make(0, -1, 0);
	t_tuple	norm = rt_vector_make(M_SQRT1_2, M_SQRT1_2, 0);

	printf("\n----TESTING RAY REFLECT----\n");
	rt_tuple_print(rt_ray_reflect(in, norm));
}

void	test_ray_normal(void)
{
	t_shape		*sphere1 = rt_sphere_make(rt_point_make(0, 0, 0), 0.5);
	t_matrix	*scale;
	t_matrix	*rotate;
	t_matrix	*combined;
	int		trgb[] = {22, 22, 22, 22};

	printf("\n----TESTING RAY NORMAL----\n");
	rt_shape_info_fill(sphere1, rt_trgb_to_color(trgb));
	scale = rt_matrix_scale(1, 0.5, 1);
	rotate = rt_matrix_rotate_z(M_PI/5);
	combined = rt_matrix_times_matrix(scale, rotate);
	rt_shape_transform_set(sphere1, combined);
	rt_tuple_print(rt_ray_normal(sphere1, rt_point_make(0, M_SQRT1_2, -M_SQRT1_2)));
	rt_free_matrix(scale);
	rt_free_matrix(rotate);
	rt_free_shape(sphere1);
}

void	test_ray_transform(void)
{
	t_ray		ray = rt_ray_make(rt_point_make(0, 0, 0), rt_vector_make(1, 1, 0));
	t_shape		*sphere1 = rt_sphere_make(rt_point_make(1, 1, 1), 5);
	t_interx	*intersections;
	int		trgb[] = {22, 22, 22, 22};

	printf("\n----TESTING RAY TRANSFORM----\n");
	rt_shape_info_fill(sphere1, rt_trgb_to_color(trgb));
	rt_shape_transform_set(sphere1, rt_matrix_translate(1, 1, 1));
	intersections = rt_ray_intersect(ray, sphere1);
	rt_interx_list_print(intersections, FLAG_A);
	rt_free_intersections(intersections);
	rt_free_shape(sphere1);
}

void	test_intersections(void)
{
	t_shape		*sphere1 = rt_sphere_make(rt_point_make(1, 1, 1), 5);
	t_ray		ray = rt_ray_make(rt_point_make(0, 0, 0), rt_vector_make(1, 1, 0));
	t_interx	*intersections;
	int		trgb[] = {22, 22, 22, 22};

	printf("\n----TESTING INTERSECTIONS----\n");
	rt_shape_info_fill(sphere1, rt_trgb_to_color(trgb));
	intersections = rt_ray_intersect(ray, sphere1);
	rt_intersect_add_end(intersections, rt_ray_intersect(ray, sphere1));
	rt_intersect_add_end(intersections, rt_ray_intersect(ray, sphere1));
	rt_intersect_add_end(intersections, rt_ray_intersect(ray, sphere1));
	rt_intersect_add_end(intersections, rt_ray_intersect(ray, sphere1));
	rt_intersect_add_end(intersections, rt_ray_intersect(ray, sphere1));
	rt_intersect_sort(&intersections, rt_float_smaller_equal);
	rt_interx_list_print(rt_intersect_hit(intersections), FLAG_A);
	rt_interx_list_print(intersections, FLAG_A);
	rt_free_intersections(intersections);
	rt_free_shape(sphere1);
}

void	test_tuple(void)
{
	t_tuple	a;
	t_tuple	b;

	printf("\n----TESTING TUPLE----\n");
	a = rt_vector_make(-5, 0, 0);
	b = rt_vector_make(0, 5, 0);
	rt_tuple_print(rt_vector_cross(a, b));
	printf("dot = %f\n", rt_vector_dot(a, b));
	printf("magnitude = %f\n", \
	rt_vector_magnitude(rt_tuple_divide(a, rt_vector_magnitude(a))));
}

void	test_matrix_sheer(void)
{
	t_matrix	*sheer = rt_matrix_sheer(rt_tuple_make(0, 0, 0, 0), rt_tuple_make(0, 0, 1, 0), rt_tuple_make(0, 0, 0, 0));
	t_matrix	*point = rt_tuple_to_matrix(rt_point_make(2, 3, 4));

	printf("\n----TESTING MATRIX SHEER----\n");
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(sheer, point)));
	rt_free_matrix(sheer);
	rt_free_matrix(point);
}

void	test_matrix_rotate(void)
{
	t_matrix	*point = rt_tuple_to_matrix(rt_point_make(1, 1, 0));
	t_matrix	*vector = rt_tuple_to_matrix(rt_vector_make(0, 1, 1));
	t_matrix	*rotate_x = rt_matrix_rotate_x(M_PI_2);
	t_matrix	*rotate_y = rt_matrix_rotate_y(M_PI_2);
	t_matrix	*rotate_z = rt_matrix_rotate_z(M_PI_2);

	printf("\n----TESTING MATRIX ROTATE----\n");
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(rotate_x, point)));
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(rotate_y, point)));
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(rotate_z, point)));
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(rotate_x, vector)));
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(rotate_y, vector)));
	rt_free_matrix(rt_matrix_print(rt_matrix_times_matrix(rotate_z, vector)));
	rt_free_matrix(point);
	rt_free_matrix(vector);
	rt_free_matrix(rotate_x);
	rt_free_matrix(rotate_y);
	rt_free_matrix(rotate_z);
}

void	test_matrix_scale(void)
{
	t_tuple		point = rt_point_make(1, 2, 3);
	t_tuple		vector = rt_vector_make(3, 2, 1);
	t_matrix	*mtx_scale;
	t_matrix	*mtx_mirror;
	t_matrix	*mtx_point;
	t_matrix	*mtx_vector;
	t_matrix	*res_point;
	t_matrix	*res_vector;

	printf("\n----TESTING MATRIX TRANSLATE----\n");
	mtx_scale = rt_matrix_scale(-1, -2, -3);
	rt_matrix_print(mtx_scale);
	mtx_mirror = rt_matrix_scale(-1, 1, 1);
	rt_matrix_print(mtx_mirror);
	mtx_point = rt_tuple_to_matrix(point);
	rt_matrix_print(mtx_point);
	mtx_vector = rt_tuple_to_matrix(vector);
	rt_matrix_print(mtx_vector);
	res_point = rt_matrix_times_matrix(mtx_scale, mtx_point);
	res_vector = rt_matrix_times_matrix(mtx_scale, mtx_vector);
	rt_matrix_print(res_point);
	rt_matrix_print(res_vector);
	rt_free_matrix(res_point);
	rt_free_matrix(res_vector);
	res_point = rt_matrix_times_matrix(mtx_mirror, mtx_point);
	res_vector = rt_matrix_times_matrix(mtx_mirror, mtx_vector);
	rt_matrix_print(res_point);
	rt_matrix_print(res_vector);
	rt_free_matrix(mtx_scale);
	rt_free_matrix(mtx_point);
	rt_free_matrix(mtx_vector);
	rt_free_matrix(res_point);
	rt_free_matrix(res_vector);
	rt_free_matrix(mtx_mirror);
}

void	test_matrix_translate(void)
{
	t_tuple		tuple_a = (t_tuple){.x = 1, .y = 2, .z = 3, .w = 1};
	t_matrix	*mtx_translate;
	t_matrix	*mtx_a;
	t_matrix	*res;

	printf("\n----TESTING MATRIX TRANSLATE----\n");
	mtx_translate = rt_matrix_translate(-1, -1, -1);
	rt_matrix_print(mtx_translate);
	mtx_a = rt_tuple_to_matrix(tuple_a);
	rt_matrix_print(mtx_a);
	res = rt_matrix_times_matrix(mtx_translate, mtx_a);
	rt_matrix_print(res);
	rt_free_matrix(mtx_a);
	rt_free_matrix(mtx_translate);
	rt_free_matrix(res);
}

void	test_matrix_inverse(void)
{
	t_matrix	*mtx_a;
	t_matrix	*mtx_b;
	t_matrix	*mtx_c;
	t_matrix	*mtx_inv;
	t_matrix	*mtx_ans;
	double		num_arr_1[] = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	double		num_arr_2[] = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5};

	printf("\n----TESTING MATRIX INVERSE----\n");
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
	rt_matrix_print(mtx_b);
	rt_free_matrix(mtx_a);
	rt_free_matrix(mtx_b);
	rt_free_matrix(mtx_c);
	rt_free_matrix(mtx_inv);
	rt_free_matrix(mtx_ans);
}

void	test_matrix_maths(void)
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
	t_mtx_index		start;
	t_mtx_index		end;
	double		arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	double		arr2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
	double		arr3[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9, -2, -8, 3, 5, -3, 1, 7, 3, 1};
	double		arr4[] = {-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};

	printf("\n----TESTING MATRIX MATHS----\n");
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
	mtx_id_test = rt_matrix_get_identity(mtx1->row);
	rt_matrix_print(mtx_id_test);
	rt_matrix_print(rt_matrix_transpose(mtx_id_test));
	start = (t_mtx_index){0};
	end = (t_mtx_index){.row = 1, .column = 2};
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
