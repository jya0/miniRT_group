/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:31:50 by jyao              #+#    #+#             */
/*   Updated: 2023/05/12 15:32:03 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_tuple_print(t_tuple	tuple)
{
	printf("tuple value: x=%f y=%f z=%f w=%f\n"\
	, tuple.x, tuple.y, tuple.z, tuple.w);
}
