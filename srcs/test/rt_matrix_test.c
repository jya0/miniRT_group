/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:13 by jyao              #+#    #+#             */
/*   Updated: 2023/05/12 15:38:16 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_matrix	*rt_matrix_print(t_matrix *mtx)
{
	unsigned int	i;
	unsigned int	j;

	if (mtx == NULL)
		return (NULL);
	i = 0;
	while (i < mtx->row)
	{
		printf("\n|");
		j = 0;
		while (j < mtx->column)
		{
			printf("%f| ", mtx->matrix[i][j]);
			j++;
		}
		i++;
	}
	return (mtx);
}
