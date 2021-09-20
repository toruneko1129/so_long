/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:24:02 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 16:48:39 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_image_nullsafe(void *mlx, void *img)
{
	if (mlx != NULL && img != NULL)
		mlx_destroy_image(mlx, img);
}

void	free_data_error(t_data *data)
{
	int		i;

	free(data->msg);
	i = -1;
	destroy_image_nullsafe(data->mlx, data->space.tex.img);
	destroy_image_nullsafe(data->mlx, data->wall.tex.img);
	while (++i < IMG_NUM_OF_COLLECTIBLE)
	{
		destroy_image_nullsafe(data->mlx, (data->collectible)[i].tex.img);
		destroy_image_nullsafe(data->mlx, (data->exit)[i].tex.img);
	}
	i = -1;
	while (++i < IMG_NUM_OF_PLAYER)
	{
		destroy_image_nullsafe(data->mlx, (data->player)[i].tex.img);
		destroy_image_nullsafe(data->mlx, (data->enemy)[i].tex.img);
	}
	destroy_image_nullsafe(data->mlx, data->tex.img);
	if (data->mlx != NULL && data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	free_2darray(data->field);
}

static void	print_result(t_data *data)
{
	if (*(data->msg) != 'M')
		printf("%s\n", data->msg);
	free(data->msg);
}

int	free_data_exit(t_data *data)
{
	int		i;

	print_result(data);
	mlx_destroy_image(data->mlx, data->space.tex.img);
	mlx_destroy_image(data->mlx, data->wall.tex.img);
	i = -1;
	while (++i < IMG_NUM_OF_COLLECTIBLE)
	{
		mlx_destroy_image(data->mlx, (data->collectible)[i].tex.img);
		mlx_destroy_image(data->mlx, (data->exit)[i].tex.img);
	}
	i = -1;
	while (++i < IMG_NUM_OF_PLAYER)
	{
		mlx_destroy_image(data->mlx, (data->player)[i].tex.img);
		mlx_destroy_image(data->mlx, (data->enemy)[i].tex.img);
	}
	mlx_destroy_image(data->mlx, data->tex.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_2darray(data->field);
	exit(EXIT_SUCCESS);
	return (0);
}
