/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:04:49 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 18:14:53 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	is_supported_element(t_element *element)
{
	if (ft_strnstr(\
	RT_SUPPORTED_ELEMENTS, element->id_str, \
	ft_strlen(RT_SUPPORTED_ELEMENTS)) == NULL)
		return (1);
	return (0);
}

static t_parse_fun	get_parse_fun(char *id_str)
{
	if (ft_strncmp(id_str, "A", ft_strlen(id_str)) == 0)
		return (rt_parse_ambient);
	else if (ft_strncmp(id_str, "C", ft_strlen(id_str)) == 0)
		return (rt_parse_camera);
	else if (ft_strncmp(id_str, "L", ft_strlen(id_str)) == 0)
		return (rt_parse_light);
	else if (ft_strncmp(id_str, "sp", ft_strlen(id_str)) == 0)
		return (rt_parse_sphere);
	else if (ft_strncmp(id_str, "pl", ft_strlen(id_str)) == 0)
		return (rt_parse_plane);
	return (rt_parse_cyclinder);
}

int	rt_parse_check(t_element *head_element)
{
	t_element	*tmp_element;

	if (head_element == NULL)
		return (1);
	rt_file_print(head_element);
	tmp_element = head_element;
	while (tmp_element != NULL)
	{
		if (is_supported_element(tmp_element) != 0)
			return (1);
		if (get_parse_fun(tmp_element->id_str)(tmp_element) != 0)
			return (1);
		tmp_element = tmp_element->next;
	}
	return (0);
}
