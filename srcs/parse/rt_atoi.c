/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:10:30 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 19:55:49 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	hft_issign(const char c)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			return (-1);
		return (1);
	}
	return (0);
}

int	rt_is_str_digit(char const *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (1);
		str++;
	}
	return (0);
}

int	rt_atoi(const char *str)
{
	long long int	num;
	int				sign;
	static int		fail_flag;

	if (!str)
		return (0);
	if (ft_strncmp(str, RT_ATOI_FAIL_FLAG, ft_strlen(str)) == 0)
		return (fail_flag);
	num = 0;
	sign = hft_issign(*str);
	if (sign != 0)
		str++;
	if (*str == '\0')
		fail_flag = 1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0') * (1 - 2 * (sign < 0));
		str++;
	}
	if (*str != '\0')
		fail_flag = 1;
	if (num >= INT32_MIN && num <= INT32_MAX)
		return ((int)num);
	fail_flag = 1;
	return (0);
}
