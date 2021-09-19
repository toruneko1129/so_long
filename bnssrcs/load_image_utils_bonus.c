/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:20:33 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 16:48:46 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load_collectible(t_data *data)
{
	const char	*path[IMG_NUM_OF_COLLECTIBLE] =
			{IMG_COLLECTIBLE1,
			IMG_COLLECTIBLE2};
	int			i;

	i = -1;
	while (++i < IMG_NUM_OF_COLLECTIBLE)
	{
		load_image_from_xpm(&((data->collectible)[i]), data->mlx,
			(char *)path[i]);
		if (data->collectible[i].tex.img == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}

int	load_exit(t_data *data)
{
	const char	*path[IMG_NUM_OF_EXIT] =
			{IMG_EXIT1,
			IMG_EXIT2};
	int			i;

	i = -1;
	while (++i < IMG_NUM_OF_EXIT)
	{
		load_image_from_xpm(&((data->exit)[i]), data->mlx,
			(char *)path[i]);
		if (data->exit[i].tex.img == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}

int	load_player(t_data *data)
{
	const char	*path[IMG_NUM_OF_PLAYER] =
			{IMG_PLAYER1,
			IMG_PLAYER2,
			IMG_PLAYER3,
			IMG_PLAYER4,
			IMG_PLAYER5,
			IMG_PLAYER6,
			IMG_PLAYER7,
			IMG_PLAYER8};
	int			i;

	i = -1;
	while (++i < IMG_NUM_OF_PLAYER)
	{
		load_image_from_xpm(&((data->player)[i]), data->mlx,
			(char *)path[i]);
		if (data->player[i].tex.img == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}

int	load_enemy(t_data *data)
{
	const char	*path[IMG_NUM_OF_ENEMY] =
			{IMG_ENEMY1,
			IMG_ENEMY2,
			IMG_ENEMY3,
			IMG_ENEMY4,
			IMG_ENEMY5,
			IMG_ENEMY6,
			IMG_ENEMY7,
			IMG_ENEMY8};
	int			i;

	i = -1;
	while (++i < IMG_NUM_OF_ENEMY)
	{
		load_image_from_xpm(&((data->enemy)[i]), data->mlx,
			(char *)path[i]);
		if (data->enemy[i].tex.img == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}
