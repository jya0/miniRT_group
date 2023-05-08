/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:19:14 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 16:48:39 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_file_print(t_element *head_element)
{
	int			i;
	t_element	*tmp;

	tmp = head_element;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->info[i] != NULL)
		{
			printf("%s", tmp->info[i]);
			i++;
		}
		tmp = tmp->next;
	}
}
