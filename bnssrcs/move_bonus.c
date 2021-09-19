/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:21:48 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 16:49:04 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_grid	get_next_pos_player(int keycode, t_data *data)
{
	t_grid	next;

	next = data->pos_player;
	if (keycode == W)
		--next.y;
	else if (keycode == S)
		++next.y;
	else if (keycode == D)
		++next.x;
	else if (keycode == A)
		--next.x;
	if (keycode == W)
		data->player_dir = 6;
	else if (keycode == S)
		data->player_dir = 4;
	else if (keycode == D)
		data->player_dir = 0;
	else if (keycode == A)
		data->player_dir = 2;
	return (next);
}

int	move_player(int keycode, t_data *data)
{
	t_grid	next;

	next = get_next_pos_player(keycode, data);
	if ((data->field)[next.y][next.x] == '1')
		return (FAILED);
	if (data->is_exit_player)
		(data->field)[data->pos_player.y][data->pos_player.x] = 'E';
	else
		(data->field)[data->pos_player.y][data->pos_player.x] = '0';
	data->is_exit_player = 0;
	if ((data->field)[next.y][next.x] == 'C')
		--(data->cnt_c);
	else if ((data->field)[next.y][next.x] == 'E')
		data->is_exit_player = 1;
	(data->field)[next.y][next.x] = 'P';
	data->pos_player = next;
	return (SUCCESS);
}
