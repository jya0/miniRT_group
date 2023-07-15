/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:29:47 by jyao              #+#    #+#             */
/*   Updated: 2023/07/13 15:49:13 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_interx	*rt_scene_intersect(t_scene *scene, t_ray ray)
{
	t_interx	*tmp_interx;
	t_interx	*interx_list;
	int			i;

	if (scene == NULL || scene->shapes == NULL)
		return (NULL);
	i = 0;
	tmp_interx = NULL;
	interx_list = NULL;
	while (scene->shapes[i] != NULL)
	{
		tmp_interx = rt_ray_intersect(ray, scene->shapes[i]);
		if (tmp_interx != NULL && interx_list == NULL)
			interx_list = tmp_interx;
		else if (interx_list != NULL)
			rt_intersect_add_end(interx_list, tmp_interx);
		i++;
	}
	rt_intersect_sort(&interx_list, rt_float_smaller_equal);
	return (interx_list);
}
