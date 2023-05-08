/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:39:00 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 16:46:44 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static void	rt_free_element(t_element *head_element)
{
	int			i;
	t_element	*tmp_element;

	while (head_element != NULL)
	{
		i = 0;
		while (head_element->info[i] != NULL)
			free(head_element->info[i++]);
		free(head_element->info);
		tmp_element = head_element;
		head_element = head_element->next;
		free(tmp_element);
	}
}

void	rt_free(t_minirt *minirt)
{
	if (minirt == NULL)
		return ;
	rt_free_element(minirt->head_element);
}
