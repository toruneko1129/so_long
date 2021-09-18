/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:20:33 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/18 19:20:34 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_collectible(t_data *data)
{
	const char	*path[2] =
			{IMG_COLLECTIBLE1,
			IMG_COLLECTIBLE2};
	int			i;

	i = -1;
	while (++i < 2)
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
	const char	*path[2] =
			{IMG_EXIT1,
			IMG_EXIT2};
	int			i;

	i = -1;
	while (++i < 2)
	{
		load_image_from_xpm(&((data->exit)[i]), data->mlx,
			(char *)path[i]);
		if (data->exit[i].tex.img == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}
