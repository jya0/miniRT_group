/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:52:35 by jyao              #+#    #+#             */
/*   Updated: 2023/06/11 08:34:47 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

t_img	*rt_img_make(void *mlx, unsigned int width, unsigned int height)
{
	t_img	*img;

	if (mlx == NULL)
		return (rt_error_write(ERROR_IMG_MAKE, NULL), NULL);
	img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (img == NULL)
		return (rt_error_write(ERROR_MEM_ALLOC, NULL), NULL);
	img->mlx = mlx;
	img->img_mlx = mlx_new_image(mlx, width, height);
	if (img->img_mlx == NULL)
		return (rt_error_write(ERROR_IMG_MAKE, NULL), img);
	img->img_addr = \
		mlx_get_data_addr(img->img_mlx, &img->bpp, &img->ln_size, &img->endian);
	if (img->img_addr == NULL)
		return (rt_error_write(ERROR_IMG_MAKE, NULL), img);
	return (img);
}

void	rt_img_edit_pixel(t_img *img, int pixel_color, \
unsigned int x, unsigned int y)
{
	char	*pixel_addr;

	pixel_color = mlx_get_color_value(img->mlx, pixel_color);
	pixel_addr = img->img_addr + (y * img->ln_size) \
		+ (x * (img->bpp / 8));
	(*(int *)pixel_addr) = pixel_color;
}

void	rt_free_img(t_img *img)
{
	if (img != NULL)
	{
		if (img->img_mlx != NULL)
			mlx_destroy_image(img->mlx, img->img_mlx);
		free(img);
	}
}
