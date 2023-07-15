/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:41:21 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 10:52:35 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_EVENT_H
# define RT_EVENT_H

# include	"minirt.h"

typedef struct s_minirt	t_minirt;

/*Supported Xlib events in MacOS*/
enum e_xevents_macos {
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	MOUSE_PRESS = 4,
	MOUSE_RELEASE = 5,
	MOUSE_MOVE = 6,
	EXPOSE = 12,
	WIN_DESTROY = 17
};

/*Keycodes for this SPECIFIC MACOS MACHINE ONLY!!!*/
enum e_keycodes_this_macos {
	W_UP = 13,
	A_LEFT = 0,
	S_DOWN = 1,
	D_RIGHT = 2,
	ESC_KEY = 53
};

void	rt_event(t_minirt *minirt);

#endif