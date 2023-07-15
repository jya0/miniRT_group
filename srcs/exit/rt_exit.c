/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:39:10 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 10:53:27 by jyao             ###   ########.fr       */
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
