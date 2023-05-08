/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:07:09 by jyao              #+#    #+#             */
/*   Updated: 2023/05/08 13:18:24 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

//BUFFER_SIZE is a variable defined during compile time given by
//-D BUFFER_SIZE=n

static char	*hft_strjoin(char *s1, char *s2)
{
	char	*combined;
	size_t	cou[2];

	if (!s1 && !s2)
		return (NULL);
	combined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!combined)
		return (NULL);
	cou[0] = 0;
	cou[1] = 0;
	if (s1)
	{
		while (s1[cou[1]])
			combined[cou[0]++] = s1[cou[1]++];
		free(s1);
		cou[1] = 0;
	}
	if (s2)
	{
		while (s2[cou[1]])
			combined[cou[0]++] = s2[cou[1]++];
		free(s2);
	}
	combined[cou[0]] = '\0';
	return (combined);
}

static char	*hft_read_until_newline(int fd)
{
	char	*buffer;
	size_t	i;
	char	isnewline;
	ssize_t	readreturn;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + sizeof(char));
	if (!buffer)
		return (NULL);
	readreturn = read(fd, buffer, BUFFER_SIZE);
	if (readreturn <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[readreturn] = '\0';
	isnewline = 0;
	i = 0;
	while (buffer[i] && !isnewline)
		isnewline = buffer[i++] == '\n';
	if (!isnewline)
		buffer = hft_strjoin(buffer, hft_read_until_newline(fd));
	return (buffer);
}

static char	*hft_realloc(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*newbuffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	j = ft_strlen(buffer);
	newbuffer = NULL;
	if (j - i > 1)
	{
		newbuffer = (char *)malloc(j - i);
		if (!newbuffer)
			return (NULL);
		j = 0;
		while (buffer[i + 1 + j])
		{
			newbuffer[j] = buffer[i + 1 + j];
			j++;
		}
		newbuffer[j] = '\0';
	}
	free(buffer);
	return (newbuffer);
}

static char	*hft_yoink_nextline(char *buffer)
{
	size_t	i;
	char	*nextline;
	char	isnewline;

	isnewline = 0;
	i = 0;
	while (buffer[i] && !isnewline)
		isnewline = buffer[i++] == '\n';
	nextline = (char *)malloc(sizeof(char) * i + sizeof(char));
	if (!nextline)
		return (NULL);
	nextline[i] = '\0';
	while (i--)
		nextline[i] = buffer[i];
	return (nextline);
}

char	*rt_gnl(int fd)
{
	static char	*buffer[1024];
	char		*nextline;
	char		isnewline;
	size_t		i;

	if (fd < 0 || fd > 1023)
		return (NULL);
	isnewline = 0;
	i = 0;
	while (buffer[fd] && buffer[fd][i] && !isnewline)
		isnewline = buffer[fd][i++] == '\n';
	if (!isnewline)
		buffer[fd] = hft_strjoin(buffer[fd], hft_read_until_newline(fd));
	if (!buffer[fd])
		return (NULL);
	nextline = hft_yoink_nextline(buffer[fd]);
	buffer[fd] = hft_realloc(buffer[fd]);
	return (nextline);
}
