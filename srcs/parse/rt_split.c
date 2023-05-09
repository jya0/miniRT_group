/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:14:20 by jyao              #+#    #+#             */
/*   Updated: 2023/05/09 20:20:26 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

static int	delimiterlen(char const *s, char *charset)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(charset, s[i]) != NULL)
		i++;
	return (i);
}

static int	wordlen(char const *s, char *charset)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(charset, s[i]) == NULL)
		i++;
	return (i);
}

static int	linelen(char const *s, char *charset)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	while (s[i])
	{
		if (flag == 0 && ft_strchr(charset, s[i]) == NULL)
		{
			len++;
			flag = 1;
		}
		else if (flag == 1 && ft_strchr(charset, s[i]) != NULL)
			flag = 0;
		i++;
	}
	return (len);
}

char	**rt_split(char const *s, char *charset)
{
	int		i;
	int		j;
	int		llen;
	int		clen;
	char	**result;

	if (!s)
		return (0);
	llen = linelen(s, charset);
	result = (char **)malloc(sizeof(char *) * (llen + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	clen = 0;
	while (i < llen)
	{
		j += clen + delimiterlen(&s[j + clen], charset);
		clen = wordlen(&s[j], charset);
		result[i] = (char *)malloc(sizeof(char) * (clen + 1));
		if (result[i])
			ft_strlcpy(result[i++], &s[j], clen + 1);
	}
	result[i] = 0;
	return (result);
}
