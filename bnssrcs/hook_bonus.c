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

#include "so_long_bonus.h"

int	key_hook(int keycode, t_data *data)
{
	static int	cnt = 0;

	if (keycode == ESCAPE)
	{
		ft_putendl_fd(get_msg_from_keycode(keycode), STDERR);
		free_data_exit(data);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		if (!move_player(keycode, data))
			printf("Move %s, score:%d\n", get_msg_from_keycode(keycode),
				++cnt);
		if (data->cnt_c == 0 && data->is_exit_player)
		{
			printf("%s score:%d\n", CLEAR, cnt);
			free_data_exit(data);
		}
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
