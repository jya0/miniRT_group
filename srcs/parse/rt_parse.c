/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:10:08 by jyao              #+#    #+#             */
/*   Updated: 2023/05/31 09:30:36 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	rt_parse(t_minirt *minirt, char *rt_file)
{
	unsigned int	shapes_total;
	unsigned int	objs_total;

	shapes_total = 0;
	objs_total = 0;
	minirt->head_element = rt_parse_load(rt_file);
	if (rt_parse_and_check(minirt->head_element, &shapes_total, &objs_total))
	{
		rt_error_write(ERROR_FILE_FORMAT, rt_file);
		rt_exit(minirt);
	}
	minirt->scene = rt_scene_make(shapes_total, objs_total);
	if (minirt->scene == NULL)
		rt_exit(minirt);
}
