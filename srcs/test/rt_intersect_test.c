/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:29:44 by jyao              #+#    #+#             */
/*   Updated: 2023/05/23 13:32:12 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_interx_list_print(t_interx *head, int flag)
{
	t_interx	*tmp;

	if (head == NULL)
		return ;
	if (flag & FLAG_A)
	{
		while (head != NULL)
		{
			printf("|t_val = %f|", head->t_val);
			if (head->next == NULL)
				tmp = head;
			head = head->next;
		}
	}
	if (flag & FLAG_B)
	{
		printf("\nreverse-->: ");
		while (tmp != NULL)
		{
			printf("|t_val = %f|", tmp->t_val);
			tmp = tmp->prev;
		}
	}
}
