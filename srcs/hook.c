/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:24:09 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/18 00:41:50 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		printf("%s\n", "KeyboardInterrupt");
		free_data_exit(data);
	}
	return (keycode);
}

void	reg_hooks(t_data *data)
{
	mlx_expose_hook(data->win, draw_tex, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 33, 1L << 17, free_data_exit, data);
}
