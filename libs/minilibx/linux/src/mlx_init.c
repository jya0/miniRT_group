/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 00:29:24 ol                #+#    #+#             */
/*   Updated: 2020/01/29 00:31:47 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	*mlx_init()
{
	t_xvar	*xvar;

	if (!(xvar = malloc(sizeof(*xvar))) || !(xvar->display = XOpenDisplay("")))
		return (NULL);
	xvar->screen = DefaultScreen(xvar->display);
	xvar->root = DefaultRootWindow(xvar->display);
	xvar->cmap = DefaultColormap(xvar->display, xvar->screen);
	xvar->depth = DefaultDepth(xvar->display, xvar->screen);
	if (mlx_int_get_visual(xvar) == -1)
	{
		printf(ERR_NO_TRUECOLOR);
		exit(1);
	}
	xvar->win_list = 0;
	xvar->loop_hook = 0;
	xvar->loop_param = NULL;
	xvar->do_flush = 1;
	mlx_int_deal_shm(xvar);
	if (xvar->private_cmap)
		xvar->cmap = XCreateColormap(xvar->display, xvar->root,
										xvar->visual, AllocNone);
	mlx_int_rgb_conversion(xvar);
	return (xvar);
}

/*
** pshm_format of -1 :  Not XYBitmap|XYPixmap|ZPixmap
** alpha libX need a check of the DISPLAY env var, or shm is allowed
** in remote Xserver connections.
*/

int		mlx_int_deal_shm(t_xvar *xvar)
{
	int		use_pshm;
	int		bidon;
	char	*dpy;
	char	buff[33];

	xvar->use_xshm = XShmQueryVersion(xvar->display, &bidon, &bidon, &use_pshm);
	if (xvar->use_xshm && use_pshm)
		xvar->pshm_format = XShmPixmapFormat(xvar->display);
	else
		xvar->pshm_format = -1;
	gethostname(buff, 32);
	dpy = getenv(ENV_DISPLAY);
	if (dpy && strlen(dpy) && *dpy != ':' && strncmp(dpy, buff, strlen(buff)) &&
		strncmp(dpy, LOCALHOST, strlen(LOCALHOST)))
	{
		xvar->pshm_format = -1;
		xvar->use_xshm = 0;
	}
	return (0);
}

/*
** TrueColor Visual is needed to have *_mask correctly set
*/

int		mlx_int_rgb_conversion(t_xvar *xvar)
{
	bzero(xvar->decrgb, sizeof(int) * 6);
	while (!(xvar->visual->red_mask & 1) &&
			(xvar->visual->red_mask >>= 1 || 1))
		xvar->decrgb[0]++;
	while (xvar->visual->red_mask & 1 &&
			(xvar->visual->red_mask >>= 1 || 1))
		xvar->decrgb[1]++;
	while (!(xvar->visual->green_mask & 1) &&
			(xvar->visual->green_mask >>= 1 || 1))
		xvar->decrgb[2]++;
	while (xvar->visual->green_mask & 1 &&
			(xvar->visual->green_mask >>= 1 || 1))
		xvar->decrgb[3]++;
	while (!(xvar->visual->blue_mask & 1) &&
			(xvar->visual->blue_mask >>= 1 || 1))
		xvar->decrgb[4]++;
	while (xvar->visual->blue_mask & 1 &&
			(xvar->visual->blue_mask >>= 1 || 1))
		xvar->decrgb[5]++;
	return (0);
}
