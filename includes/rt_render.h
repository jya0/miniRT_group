/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:31:50 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 14:22:25 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

typedef struct s_minirt	t_minirt;

typedef struct s_mlx_struct {
	void	*init;
	void	*window;
}				t_mlx_struct;

int	rt_render(t_minirt	*minirt);

#endif