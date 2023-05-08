/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:10:08 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 17:13:02 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_parse(t_minirt *minirt, char *rt_file)
{
	minirt->head_element = rt_parse_load(rt_file);
	if (rt_parse_check(minirt->head_element) != 0)
	{
		rt_error_write(ERROR_FILE_FORMAT, rt_file);
		rt_exit(minirt);
	}	
}
