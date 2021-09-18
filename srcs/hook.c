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

int	loop_hook(t_data *data)
{
	static int	cnt = 0;

	if (++cnt == SWITCH_INTERVAL)
	{
		data->sprite ^= 1;
		draw_tex(data);
	}
	cnt %= SWITCH_INTERVAL;
	return (0);
}
