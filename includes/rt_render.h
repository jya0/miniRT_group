/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:31:50 by jyao              #+#    #+#             */
/*   Updated: 2023/07/12 09:52:55 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# define WIN_X			500
# define WIN_Y			500
# define CAM_DIST		1
# define WIN_NAME		"MINIRT: OOO SHINY!"

typedef struct s_minirt	t_minirt;

typedef struct s_scene t_scene;

typedef struct s_scene_obj	t_scene_obj;


typedef struct s_img {
	void			*mlx;
	void			*img_mlx;
	char			*img_addr;
	int				bpp;
	int				ln_size;
	int				endian;
}	t_img;

typedef struct s_mlx_struct {
	void	*init;
	void	*window;
	t_img	*canvas;
}	t_mlx_struct;

/* rt_render.c */
int				rt_render(t_minirt	*minirt);

/* rt_lighting.c */
t_tuple			rt_lighting(\
t_tuple point_of_interx, t_interx *interx_info, t_scene *scene);

/* rt_img.c */
t_img			*rt_img_make(\
	void *mlx, unsigned int width, unsigned int height);

void			rt_img_edit_pixel(t_img *img, int pixel_color, \
	unsigned int x, unsigned int y);

void			rt_free_img(t_img *img);

#endif