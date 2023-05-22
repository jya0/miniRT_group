/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:29:44 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 13:31:43 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_interx_list_print(t_interx *head)
{
	if (head == NULL)
		return ;
	while (head != NULL)
	{
		printf("|t_val = %f|", head->t_val);
		head = head->next;
	}
}
