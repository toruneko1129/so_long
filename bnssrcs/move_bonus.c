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

static int	get_keycode(t_data data)
{
	const t_grid	player = data.pos_player;
	const t_grid	enemy = data.pos_enemy;
	const int		val[2] = {(int)ft_rand() % 100, (int)ft_rand() % 4};

	if (val[0] < RANDOM_MOVE_RATE)
	{
		if (val[1] == 0)
			return (W);
		else if (val[1] == 1)
			return (S);
		else if (val[1] == 2)
			return (D);
		else
			return (A);
	}
	else if (player.y < enemy.y && ft_strchr("0P", (data.field)[enemy.y - 1][enemy.x]) != NULL)
		return (W);
	else if (player.y > enemy.y && ft_strchr("0P", (data.field)[enemy.y + 1][enemy.x]) != NULL)
		return (S);
	else if (player.x > enemy.x && ft_strchr("0P", (data.field)[enemy.y][enemy.x + 1]) != NULL)
		return (D);
	else if (player.x < enemy.x && ft_strchr("0P", (data.field)[enemy.y][enemy.x - 1]) != NULL)
		return (A);
	return (0);
}

int	move_enemy(t_data *data)
{
	const int	keycode = get_keycode(*data);
	t_grid		next;

	if (keycode == 0)
		return (FAILED);
	next = get_next_pos(keycode, data, FALSE);
	if ((data->field)[next.y][next.x] == 'P')
		return (LOSE);
	else if ((data->field)[next.y][next.x] != '0')
		return (FAILED);
	(data->field)[data->pos_enemy.y][data->pos_enemy.x] = '0';
	(data->field)[next.y][next.x] = 'G';
	data->pos_enemy = next;
	return (SUCCESS);
}
