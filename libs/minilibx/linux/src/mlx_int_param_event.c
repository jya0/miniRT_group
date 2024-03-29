/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_param_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 00:48:05 ol                #+#    #+#             */
/*   Updated: 2020/01/29 00:49:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_int_param_undef()
{
	return (0);
}

int	mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[KeyPress].hook(
		XkbKeycodeToKeysym(xvar->display, ev->xkey.keycode, 0, 0),
		win->hooks[KeyPress].param
	);
	return (0);
}

int	mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[KeyRelease].hook(
		XkbKeycodeToKeysym(xvar->display, ev->xkey.keycode, 0, 0),
		win->hooks[KeyRelease].param
	);
	return (0);
}

int	mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[ButtonPress].hook(
		ev->xbutton.button, ev->xbutton.x, ev->xbutton.y,
		win->hooks[ButtonPress].param
	);
	return (0);
}

int	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[ButtonRelease].hook(
		ev->xbutton.button, ev->xbutton.x, ev->xbutton.y,
		win->hooks[ButtonRelease].param
	);
	return (0);
}

int	mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[MotionNotify].hook(
		ev->xbutton.x, ev->xbutton.y,
		win->hooks[MotionNotify].param
	);
	return (0);
}

int	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	if (!ev->xexpose.count)
		win->hooks[Expose].hook(win->hooks[Expose].param);
	return (0);
}


int	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[ev->type].hook(win->hooks[ev->type].param);
	return (0);
}

int	(*(g_mlx_int_param_event[]))() = {
	mlx_int_param_undef,
	mlx_int_param_undef,
	mlx_int_param_KeyPress,
	mlx_int_param_KeyRelease,
	mlx_int_param_ButtonPress,
	mlx_int_param_ButtonRelease,
	mlx_int_param_MotionNotify,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_Expose,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic
};
