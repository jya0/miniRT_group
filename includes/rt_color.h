/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:58:52 by jyao              #+#    #+#             */
/*   Updated: 2023/07/15 14:25:29 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLOR_H
# define RT_COLOR_H

/* primary color definitions in TRGB format */
# define COLOR_RED		0x00FF0000
# define COLOR_GREEN	0x0000FF00
# define COLOR_BLUE		0x000000FF
# define COLOR_YELLOW	0x00FFFF00
# define COLOR_WHITE	0x00FFFFFF
# define COLOR_BLACK	0x00000000

typedef enum e_trgb {
	TRSPT,
	RED,
	GREEN,
	BLUE,
	TRGB_COUNT
}	t_trgb;

typedef struct s_tuple	t_tuple;

/* rt_color.c */
t_tuple			rt_color_make(double t, double r, double g, double b);

t_tuple			rt_color_clamp(t_tuple color);

t_tuple			rt_trgb_to_color(int *trgb);

int				rt_color_to_trgb(t_tuple color);

/* rt_color_maths.c */
t_tuple			rt_color_add(t_tuple color1, t_tuple color2);

t_tuple			rt_color_minus(t_tuple color1, t_tuple color2);

t_tuple			rt_color_times(t_tuple color, double scale);

t_tuple			rt_color_times_color(t_tuple color1, t_tuple color2);

#endif