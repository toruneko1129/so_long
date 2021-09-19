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

static int	get_dir_from_keycode(int keycode)
{
	if (keycode == W)
		return (6);
	else if (keycode == S)
		return (4);
	else if (keycode == D)
		return (0);
	else if (keycode == A)
		return (2);
	return (0);
}

static t_grid	get_next_pos(int keycode, t_data *data, int is_player)
{
	t_grid	next;
	int		*dir;

	next = data->pos_enemy;
	dir = &(data->enemy_dir);
	if (is_player)
		next = data->pos_player;
	if (is_player)
		dir = &(data->player_dir);
	if (keycode == W)
		--next.y;
	else if (keycode == S)
		++next.y;
	else if (keycode == D)
		++next.x;
	else if (keycode == A)
		--next.x;
	if (keycode == W || keycode == S || keycode == D || keycode == A)
		*dir = get_dir_from_keycode(keycode);
	return (next);
}

int	move_player(int keycode, t_data *data)
{
	t_grid	next;

	next = get_next_pos(keycode, data, TRUE);
	if ((data->field)[next.y][next.x] == 'G')
		return (LOSE);
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

static int	get_keycode_from_idx(int idx)
{
	if (idx == 0)
		return (W);
	else if (idx == 1)
		return (A);
	else if (idx == 2)
		return (S);
	else if (idx == 3)
		return (D);
	return (0);
}

int	move_enemy(int idx, t_data *data)
{
	const int	keycode = get_keycode_from_idx(idx);
	t_grid		next;

	next = get_next_pos(keycode, data, FALSE);
	if ((data->field)[next.y][next.x] == 'P')
		return (LOSE);
	if ((data->field)[next.y][next.x] != '0')
		return (FAILED);
	(data->field)[data->pos_enemy.y][data->pos_enemy.x] = '0';
	(data->field)[next.y][next.x] = 'G';
	data->pos_enemy = next;
	return (SUCCESS);
}
