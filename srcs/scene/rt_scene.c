/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:16:34 by jyao              #+#    #+#             */
/*   Updated: 2023/06/03 15:01:47 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_scene	*rt_scene_make(unsigned int shapes_total, unsigned int objs_total)
{
	t_scene	*scene;

	if ((shapes_total + objs_total) == 0)
		return (rt_error_write(ERROR_SCENE_MAKE, NULL), NULL);
	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (scene == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	if (shapes_total > 0)
	{
		scene->shapes = \
			(t_shape **)ft_calloc(shapes_total + 1, sizeof(t_shape *));
		if (scene->shapes == NULL)
			return (rt_error_write(ERROR_MEM_ALLOC, NULL), free(scene), NULL);
		scene->shapes_total = shapes_total;
	}
	if (objs_total > 0)
	{
		scene->objs = \
			(t_scene_obj **)ft_calloc(objs_total + 1, sizeof(t_scene_obj *));
		if (scene->objs == NULL)
			return (rt_error_write(ERROR_MEM_ALLOC, NULL), \
				free(scene), free(scene->shapes), NULL);
		scene->objs_total = objs_total;
	}
	return (scene);
}

void	rt_free_scene(t_scene *scene)
{
	int	i;

	if (scene != NULL)
	{
		if (scene->shapes != NULL)
		{
			i = 0;
			while (scene->shapes[i] != NULL)
				rt_free_shape(scene->shapes[i++]);
			free(scene->shapes);
		}
		if (scene->objs != NULL)
		{
			i = 0;
			while (scene->objs[i] != NULL)
				rt_free_scene_obj(scene->objs[i++]);
			free(scene->objs);
		}
		free(scene);
	}
}
