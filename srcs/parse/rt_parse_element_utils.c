/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_element_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:22:43 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 20:22:17 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

double	rt_parse_element_double(char *arg)
{
	double	whole;
	double	fractional;
	char	*radix_point;

	if (arg == NULL)
		return (0);
	radix_point = ft_strchr(arg, '.');
	if (radix_point == NULL)
		return (rt_atoi(arg));
	if (radix_point != ft_strrchr(arg, '.') || ft_strlen(arg) <= 1)
		return (rt_atoi("ERROR"));
	*radix_point = '\0';
	whole = rt_atoi(arg);
	fractional = (double)rt_atoi(radix_point + 1) \
		/ pow(10, ft_strlen(radix_point + 1)) \
		* (1 - 2 * (ft_strchr(arg, '-') != NULL));
	*radix_point = '.';
	if (rt_is_str_digit(radix_point + 1) != 0)
		return (rt_atoi("ERROR"));
	return (whole + fractional);
}

int	rt_parse_element_double_arr(\
double *arr, char *arg, char *delim, int expected_arr_size)
{
	char	**arg_split;
	int		i;

	if (arr == NULL || arg == NULL)
		return (1);
	arg_split = rt_split(arg, delim);
	if (arg_split == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), 1);
	if (rt_parse_element_argc(arg_split) != expected_arr_size)
		return (rt_free_rt_split_arr(arg_split), 1);
	i = 0;
	while (i < expected_arr_size)
	{
		arr[i] = rt_parse_element_double(arg_split[i]);
		i++;
	}
	rt_free_rt_split_arr(arg_split);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (1);
	return (0);
}

int	rt_parse_element_int(char *arg)
{
	if (arg != NULL)
		return (rt_atoi(arg));
	return (0);
}

int	rt_parse_element_int_arr(\
int *arr, char *arg, char *delim, int expected_arr_size)
{
	char	**arg_split;
	int		i;

	if (arr == NULL || arg == NULL)
		return (1);
	arg_split = rt_split(arg, delim);
	if (arg_split == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), 1);
	if (rt_parse_element_argc(arg_split) != expected_arr_size)
		return (rt_free_rt_split_arr(arg_split), 1);
	i = 0;
	while (i < expected_arr_size)
	{
		arr[i] = rt_parse_element_int(arg_split[i]);
		i++;
	}
	rt_free_rt_split_arr(arg_split);
	if (rt_atoi(RT_ATOI_FAIL_FLAG) != 0)
		return (1);
	return (0);
}

int	rt_parse_element_argc(char **info)
{
	int	i;

	if (info == NULL)
		return (0);
	i = 0;
	while (info[i] != NULL)
		i++;
	return (i);
}
