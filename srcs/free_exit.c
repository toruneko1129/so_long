/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:24:02 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/17 23:24:03 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	if (data->mlx != NULL && data->space.tex.img != NULL)
		mlx_destroy_image(data->mlx, data->space.tex.img);
	if (data->mlx != NULL && data->wall.tex.img != NULL)
		mlx_destroy_image(data->mlx, data->wall.tex.img);
	if (data->mlx != NULL && data->collectible.tex.img != NULL)
		mlx_destroy_image(data->mlx, data->collectible.tex.img);
	if (data->mlx != NULL && data->exit.tex.img != NULL)
		mlx_destroy_image(data->mlx, data->exit.tex.img);
	if (data->mlx != NULL && data->player.tex.img != NULL)
		mlx_destroy_image(data->mlx, data->player.tex.img);
	if (data->mlx != NULL && data->tex.img != NULL)
		mlx_destroy_image(data->mlx, data->tex.img);
	if (data->mlx != NULL && data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	free_2darray(data->field);
}

int	free_data_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->space.tex.img);
	mlx_destroy_image(data->mlx, data->wall.tex.img);
	mlx_destroy_image(data->mlx, data->collectible.tex.img);
	mlx_destroy_image(data->mlx, data->exit.tex.img);
	mlx_destroy_image(data->mlx, data->player.tex.img);
	mlx_destroy_image(data->mlx, data->tex.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_2darray(data->field);
	exit(EXIT_SUCCESS);
	return (0);
}
