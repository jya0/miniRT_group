/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:34:57 by jyao              #+#    #+#             */
/*   Updated: 2023/05/25 12:44:29 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_scene_obj	*rt_scene_obj_make(t_scene_obj_type type)
{
	t_scene_obj	*scene_obj;

	scene_obj = (t_scene_obj *)ft_calloc(1, sizeof(t_scene_obj));
	if (scene_obj == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	scene_obj->obj_type = type;
}
