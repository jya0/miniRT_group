/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:27 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 20:22:53 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

/* Function to check for correct suffix */
static int	check_file_suffix(char *rt_file)
{
	char	*suffix_loc;

	if (rt_file == NULL)
		return (1);
	suffix_loc = ft_strnstr(rt_file, RT_FILE_SUFFIX, ft_strlen(rt_file));
	if (suffix_loc == NULL)
		return (1);
	else
	{
		suffix_loc += ft_strlen(RT_FILE_SUFFIX);
		while (ft_strnstr(\
		suffix_loc, RT_FILE_SUFFIX, ft_strlen(suffix_loc)) != NULL)
			suffix_loc += ft_strlen(RT_FILE_SUFFIX);
	}
	if (*suffix_loc != '\0')
		return (1);
	return (0);
}

static t_element	*new_element(char *line)
{
	t_element	*new_element;
	char		**info;

	if (line == NULL || ft_strchr(SPACE_CHARSET, *line) != NULL)
		return (NULL);
	info = rt_split(line, SPACE_CHARSET);
	if (info == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	new_element = (t_element *)ft_calloc(1, sizeof(t_element));
	if (new_element == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	new_element->info = info;
	new_element->id_str = info[0];
	new_element->next = NULL;
	return (new_element);
}

static t_element	*read_file(int fd)
{
	char		*line;
	t_element	*head_element;
	t_element	*tmp_element;
	t_element	*prev_element;

	head_element = NULL;
	tmp_element = NULL;
	prev_element = NULL;
	line = rt_gnl(fd);
	while (line != NULL)
	{
		tmp_element = new_element(line);
		free(line);
		if (tmp_element != NULL)
		{
			if (head_element == NULL)
				head_element = tmp_element;
			if (prev_element != NULL)
				prev_element->next = tmp_element;
			prev_element = tmp_element;
		}
		line = rt_gnl(fd);
	}
	return (head_element);
}

t_element	*rt_parse_load(char *rt_file)
{
	int			fd;
	t_element	*head_element;

	if (check_file_suffix(rt_file) != 0)
		rt_error_write(ERROR_FILE_NAME, rt_file);
	else
	{
		fd = open(rt_file, O_RDONLY);
		if (fd < 0)
			rt_error_write(ERROR_FILE_OPEN, rt_file);
		else
		{
			head_element = read_file(fd);
			close(fd);
			return (head_element);
		}
	}
	return (NULL);
}
