/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:09:32 by jyao              #+#    #+#             */
/*   Updated: 2023/05/02 13:14:48 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	rt_error_write(char const *msg)
{
	if (msg != NULL)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
