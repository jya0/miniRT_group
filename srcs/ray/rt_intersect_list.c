/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:20 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 18:26:35 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* the intersection list is always in ascending order of 
** each intersection's t_val
** returns the address of the node after the new_intersect
** (basically the node with the t_val that fit *cmp())
** updates the head node accordingly
*/
t_interx	*rt_intersect_add_sort(\
t_interx **head, t_interx *new_intersect, int (*cmp)(double, double))
{
	t_interx	*tmp;

	if (head == NULL || *head == NULL || new_intersect == NULL || cmp == NULL)
		return (rt_error_write(ERROR_INTERX_ADD, NULL), NULL);
	tmp = *head;
	while (tmp->next != NULL && cmp(new_intersect->t_val, tmp->t_val) == 0)
		tmp = tmp->next;
	if (tmp->next == NULL)
	{
		tmp->next = new_intersect;
		new_intersect->prev = tmp;
	}
	else
	{
		if (tmp->prev != NULL)
			tmp->prev->next = new_intersect;
		else
			*head = new_intersect;
		new_intersect->prev = tmp->prev;
		new_intersect->next = tmp;
		tmp->prev = new_intersect;
	}
	return (tmp);
}

/* appends list2 to list1's end */
void	rt_intersect_add_end(t_interx *list1, t_interx *list2)
{
	if (list1 == NULL || list2 == NULL)
		return ;
	while (list1->next != NULL)
		list1 = list1->next;
	list1->next = list2;
	list2->prev = list1;
}

/* sort the list of intersections based on the *cmp() */
void	rt_intersect_sort(t_interx **head, int (*cmp)(double, double))
{
	t_interx	*tmp;
	t_interx	*before_swap_zone;
	t_interx	*after_swap_zone;

	if (head == NULL || *head == NULL || cmp == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL && \
		(cmp(tmp->t_val, tmp->next->t_val) == 1 || (tmp->t_val >= 0 && tmp->next->t_val < 0)))
		tmp = tmp->next;
	printf("|tmp tval = %f|", tmp->t_val);
	before_swap_zone = tmp->prev;
	after_swap_zone = tmp->next->next;
	if (before_swap_zone == NULL)
		*head = tmp->next;
	else
		before_swap_zone->next = tmp->next;
	tmp->next->prev = before_swap_zone;
	tmp->next->next = tmp;
	tmp->prev = tmp->next;
	tmp->next = after_swap_zone;
	if (after_swap_zone != NULL)
	{
		after_swap_zone->prev = tmp;
		rt_intersect_sort(head, rt_float_smaller);
	}
}

t_interx	*rt_interx_list_make(\
unsigned int xcount, double *t_vals, t_shape *shape, t_ray ray)
{
	t_interx		*interx_list;
	unsigned int	i;
	t_interx		*tmp;

	if (t_vals == NULL || shape == NULL)
		return (rt_error_write(ERROR_INTERX_LIST, NULL), NULL);
	interx_list = NULL;
	i = 0;
	while (i < xcount)
	{
		tmp = rt_intersect_make(shape, ray, t_vals[i]);
		if (tmp == NULL)
			return (rt_free_intersections(interx_list), NULL);
		if (interx_list == NULL)
			interx_list = tmp;
		else
			rt_intersect_add_sort(&interx_list, tmp, rt_float_smaller);
		i++;
	}
	return (interx_list);
}
