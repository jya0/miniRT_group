/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:58:48 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 16:26:00 by jyao             ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	if (argc != 2)
		rt_error_write(ERROR_WRONG_ARGC, NULL);
	else
	{
		minirt = (t_minirt){0};
		minirt.head_element = rt_parse(argv[1]);
		rt_render(&minirt);
		test_tuple();
		rt_exit(&minirt);
	}
	return (0);
}
