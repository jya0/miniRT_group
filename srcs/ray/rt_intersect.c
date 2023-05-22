/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:12:23 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 13:38:51 by jyao             ###   ########.fr       */
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
	return (intersect);
}
