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

static void	put_str_on_window(int keycode, t_data *data, int cnt, int status)
{
	char	*nbr;

	*(data->msg) = '\0';
	nbr = ft_itoa(cnt);
	if (nbr == NULL)
	{
		free(nbr);
		data_error_exit(data, MALLOC_ERR);
	}
	if (status == LOSE)
		ft_strlcat(data->msg, GAMEOVER, MSG_SIZE);
	else if (status == FINISH)
		ft_strlcat(data->msg, CLEAR, MSG_SIZE);
	else
	{
		ft_strlcat(data->msg, "Move ", MSG_SIZE);
		ft_strlcat(data->msg, get_msg_from_keycode(keycode), MSG_SIZE);
		ft_strlcat(data->msg, ", score:", MSG_SIZE);
		ft_strlcat(data->msg, nbr, MSG_SIZE);
	}
	free(nbr);
}

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
			put_str_on_window(keycode, data, cnt, LOSE);
			free_data_exit(data);
		}
		else if (data->cnt_c == 0 && data->is_exit_player)
		{
			put_str_on_window(keycode, data, cnt, FINISH);
			free_data_exit(data);
		}
		else if (res == SUCCESS)
			put_str_on_window(keycode, data, ++cnt, CONTINUE);
	}
	return (keycode);
}

static int	loop_hook2(t_data *data)
{
	static int	cnt = 0;

	if (++cnt == MOVE_ENEMY)
	{
		cnt = 0;
		if (move_enemy(data) == LOSE)
		{
			put_str_on_window(0, data, cnt, LOSE);
			free_data_exit(data);
		}
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
