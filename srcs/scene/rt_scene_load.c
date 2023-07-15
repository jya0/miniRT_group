/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:52:51 by jyao              #+#    #+#             */
/*   Updated: 2023/07/13 16:16:48 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	check_ACL(t_scene *scene)
{
	if (scene == NULL || \
		scene->ambient == NULL || scene->camera == NULL \
		|| scene->light == NULL)
		return (rt_error_write(ERROR_LOAD_ACL, NULL));
	return (0);
}

static t_load_fun	get_load_fun(char *id_str)
{
	if (ft_strncmp(id_str, "A", ft_strlen(id_str)) == 0)
		return (rt_load_ambient);
	if (ft_strncmp(id_str, "C", ft_strlen(id_str)) == 0)
		return (rt_load_camera);
	else if (ft_strncmp(id_str, "L", ft_strlen(id_str)) == 0)
		return (rt_load_light);
	else if (ft_strncmp(id_str, "sp", ft_strlen(id_str)) == 0)
		return (rt_load_sphere);
/* 	else if (ft_strncmp(id_str, "pl", ft_strlen(id_str)) == 0)
		return (rt_load_plane); */
	// else if (ft_strncmp(id_str, "cy", ft_strlen(id_str)) == 0)
	// 	return (rt_load_cylinder);
	return (NULL);
}

int	rt_scene_load(t_minirt *minirt)
{
	t_element	*tmp_element;
	t_load_fun	load_fun;

	tmp_element = minirt->head_element;
	while (tmp_element != NULL)
	{
		load_fun = get_load_fun(tmp_element->id_str);
		if (load_fun == NULL || load_fun(minirt->scene, tmp_element) != 0)
			return (1);
		tmp_element = tmp_element->next;
	}
	if (check_ACL(minirt->scene))
		return (1);
	return (0);
}
