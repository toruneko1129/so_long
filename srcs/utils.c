/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:38:02 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 16:42:26 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_2darray_size(t_data *data)
{
	data->h = 0;
	while ((data->field)[data->h] != NULL)
		++(data->h);
	data->w = ft_strlen((data->field)[0]);
}

void	free_2darray(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

t_image	get_image_from_char(t_data data, char c)
{
	if (c == '0')
		return (data.space);
	else if (c == '1')
		return (data.wall);
	else if (c == 'C')
		return ((data.collectible)[data.sprite]);
	else if (c == 'E')
		return (data.exit);
	else
		return (data.player);
}
