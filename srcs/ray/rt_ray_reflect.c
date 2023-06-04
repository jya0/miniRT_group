/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:42:29 by jyao              #+#    #+#             */
/*   Updated: 2023/06/04 18:24:43 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* explained at
** http://www.sunshine2k.de/articles/coding/vectorreflection/
** vectorreflection.html\
** #:~:text=Reflection%20in%20a%20nutshell%3A&text=
** The%20formula%20w%20%3D%20v%20%2D%202,
** not%20a%20point%20in%20space
*/
t_tuple	rt_ray_reflect(t_tuple in_vect, t_tuple norm_vect)
{
	double	dot_product;

	dot_product = rt_vector_dot(in_vect, norm_vect);
	return (rt_tuple_minus(in_vect, \
		rt_tuple_times(norm_vect, 2 * dot_product)));
}
