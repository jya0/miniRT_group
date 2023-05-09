/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:19:58 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 15:56:12 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_check_int_arr_range(int *arr, int min, int max, int arr_size)
{
	int	i;

	if (arr == NULL)
		return (1);
	i = 0;
	while (i < arr_size)
	{
		if (arr[i] < min || arr[i] > max)
			return (1);
		i++;
	}
	return (0);
}

int	rt_check_int_range(int int_val, int min, int max)
{
	return (int_val < min || int_val > max);
}

int	rt_check_double_arr_range(\
double *arr, double min, double max, int arr_size)
{
	int	i;

	if (arr == NULL)
		return (1);
	i = 0;
	while (i < arr_size)
	{
		if (arr[i] < min || arr[i] > max)
			return (1);
		i++;
	}
	return (0);
}

int	rt_check_double_range(double double_val, double min, double max)
{
	return (double_val < min || double_val > max);
}
