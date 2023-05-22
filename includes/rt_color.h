/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:58:52 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 17:07:33 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLOR_H
# define RT_COLOR_H

typedef enum e_trgb {
	TRSPT,
	RED,
	GREEN,
	BLUE,
	TRGB_COUNT
}	t_trgb;

typedef struct s_tuple	t_tuple;

t_tuple			rt_color_clamp(t_tuple color);

t_tuple			rt_color_add(t_tuple color1, t_tuple color2);

t_tuple			rt_color_minus(t_tuple color1, t_tuple color2);

t_tuple			rt_color_times(t_tuple color, double scale);

t_tuple			rt_color_times_color(t_tuple color1, t_tuple color2);

#endif