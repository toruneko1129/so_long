/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 23:24:09 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 16:48:42 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_data *data)
{
	static int	cnt = 0;
	int			res;

	if (keycode == ESCAPE)
		free_data_exit(data);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		res = move_player(keycode, data);
		if (res == LOSE)
		{
			printf(GAMEOVER);
			printf("\n");
			free_data_exit(data);
		}
		else if (res == SUCCESS)
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

static int	loop_hook2(t_data *data)
{
	static int	cnt = 0;
	int			val;
	int			res;

	if (++cnt == MOVE_ENEMY)
	{
		while (1)
		{
			val = (int)(ft_rand() % 4);
			res = move_enemy(val, data);
			if (res == LOSE)
			{
				printf(GAMEOVER);
				printf("\n");
				free_data_exit(data);
			}
			else if (res == SUCCESS)
				break ;
		}
		cnt = 0;
		draw_tex(data);
	}
	return (0);
}

int	loop_hook(t_data *data)
{
	static int	cnt = 0;

	if (++cnt == SWITCH_INTERVAL)
	{
		data->sprite ^= 1;
		draw_tex(data);
		cnt = 0;
	}
	loop_hook2(data);
	return (0);
}
