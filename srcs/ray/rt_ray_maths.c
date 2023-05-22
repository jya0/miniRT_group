/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:48:30 by jyao              #+#    #+#             */
/*   Updated: 2023/05/19 11:50:50 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_tuple	rt_ray_position(t_ray ray, double t)
{
	return (rt_tuple_add(ray.origin, rt_tuple_times(ray.direction, t)));
}
