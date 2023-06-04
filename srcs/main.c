/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:58:48 by jyao              #+#    #+#             */
/*   Updated: 2023/06/04 17:50:12 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	if (argc != 2)
		rt_error_write(ERROR_WRONG_ARGC, NULL);
	else
	{
		minirt = (t_minirt){0};
		rt_parse(&minirt, argv[1]);
		test_tuple();
		test_matrix_maths();
		test_matrix_inverse();
		test_matrix_translate();
		test_matrix_scale();
		test_matrix_rotate();
		test_matrix_sheer();
		// test_fma_speed();
		test_intersections();
		test_ray_transform();
		test_ray_normal();
		test_ray_reflect();
		// rt_render(&minirt);
		rt_exit(&minirt);
	}
	return (0);
}
