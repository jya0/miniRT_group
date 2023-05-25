/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:39:00 by jyao              #+#    #+#             */
/*   Updated: 2023/05/24 15:26:16 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_free_rt_split_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

static void	rt_free_element(t_element *head_element)
{
	t_element	*tmp_element;

	while (head_element != NULL)
	{
		tmp_element = head_element;
		rt_free_rt_split_arr(tmp_element->info);
		tmp_element->id_str = NULL;
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
