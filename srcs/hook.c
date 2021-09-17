/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:24:09 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/17 23:24:09 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		free_data(data);
		exit(0);
	}
	return (keycode);
}
