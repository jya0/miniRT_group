/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:12:23 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 22:01:55 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_free_intersections(t_interx *head)
{
	t_interx	*tmp;

	if (head == NULL)
		return ;
	tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}

static void	if_ray_inside(t_interx *intersect)
{
	double	eye_dot_norm;

	eye_dot_norm = rt_vector_dot(intersect->eye_vect, intersect->norm_vect);
	if (!rt_float_bigger_equal(eye_dot_norm, 0))
	{
		intersect->inside = 1;
		intersect->norm_vect = rt_tuple_negate(intersect->norm_vect);
	}
}

t_interx	*rt_intersect_make(t_shape *shape, t_ray ray, double t_val)
{
	t_interx	*intersect;

	if (shape == NULL)
		return (rt_error_write(ERROR_INTERX_MAKE, NULL), NULL);
	intersect = (t_interx *)ft_calloc(1, sizeof(t_interx));
	if (intersect == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	intersect->shape = shape;
	intersect->ray = ray;
	intersect->t_val = t_val;
	intersect->interx_p = rt_ray_position(ray, t_val);
	intersect->eye_vect = rt_tuple_negate(ray.direction);
	intersect->norm_vect = \
		rt_vector_normalize(rt_ray_normal(shape, intersect->interx_p));
	if_ray_inside(intersect);
	intersect->over_point = \
		rt_tuple_add(intersect->interx_p, \
			rt_tuple_times(intersect->norm_vect, RT_EPSILON));
	return (intersect);
}

/* This is just a quick function to return the first node with a postive t_val
** this works as is, due to the previously implemented functions in
** rt_intersect_sort()
 */
t_interx	*rt_intersect_hit(t_interx	*head)
{
	t_interx	*smallest_positive;

	if (head == NULL)
		return (NULL);
	smallest_positive = head;
	while (smallest_positive != NULL && \
		rt_float_bigger_equal(smallest_positive->t_val, 0) == 0)
		smallest_positive = smallest_positive->next;
	return (smallest_positive);
}
