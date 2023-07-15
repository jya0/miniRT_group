/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:39:10 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 13:23:21 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"minirt.h"

int	rt_exit(t_minirt *minirt)
{
	rt_free(minirt);
	// perror(strerror(errno));
	exit(errno);
	return (errno);
}
