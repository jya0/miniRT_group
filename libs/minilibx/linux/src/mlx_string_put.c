/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:37:58 ol                #+#    #+#             */
/*   Updated: 2020/01/29 01:38:00 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_string_put(t_xvar *xvar, t_win_list *win,
					int x, int y, int color, char *string)
{
	XGCValues	xgcv;

	xgcv.foreground = mlx_int_get_good_color(xvar, color);
	XChangeGC(xvar->display, win->gc, GCForeground, &xgcv);
	XDrawString(xvar->display, win->window, win->gc, x, y,
				string, strlen(string));
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (0);
}
