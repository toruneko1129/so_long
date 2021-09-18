/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:23:47 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/17 23:26:29 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectible(t_data *data)
{
	int		i;
	int		j;

	get_2darray_size(data);
	i = -1;
	while (++i < data->h)
	{
		j = -1;
		while (++j < data->w)
		{
			if ((data->field)[i][j] == 'C')
				++(data->cnt_c);
		}
	}
}

void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		data_error_exit(data, MALLOC_ERR);
	data->win = mlx_new_window(data->mlx, IMG_SIZE * data->w,
			IMG_SIZE * data->h, "so_long");
	if (data->win == NULL)
		data_error_exit(data, MALLOC_ERR);
}

void	load_image_from_xpm(t_image *image, void *mlx, char *path)
{
	image->tex.img = mlx_xpm_file_to_image(mlx, path, &(image->w), &(image->h));
	image->tex.addr = mlx_get_data_addr(image->tex.img, &(image->tex.bits),
			&(image->tex.line), &(image->tex.endian));
	image->path = path;
}

void	load_images(t_data *data)
{
	data->sprite = 0;
	load_image_from_xpm(&(data->space), data->mlx, IMG_SPACE);
	load_image_from_xpm(&(data->wall), data->mlx, IMG_WALL);
	if (data->space.tex.img == NULL || data->wall.tex.img == NULL
		|| load_collectible(data) || load_exit(data)
		|| load_player(data))
		data_error_exit(data, MALLOC_ERR);
}

void	reg_hooks(t_data *data)
{
	mlx_expose_hook(data->win, draw_tex, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 33, 1L << 17, free_data_exit, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_loop(data->mlx);
}
