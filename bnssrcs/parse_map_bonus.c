/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:55:58 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 22:43:48 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*check_shape_of_map(char **field)
{
	size_t	len;
	int		i;

	if (field[0] == NULL || ft_strlen(field[0]) <= 1)
		return (MAP_EMPTY);
	len = ft_strlen(field[0]);
	i = -1;
	while (field[++i] != NULL)
	{
		if (ft_strlen(field[i]) != len)
			return (MAP_INVALID_SHAPE);
		if (field[i][ft_strlen(field[i]) - 1] != '\n')
			return (MAP_MISS_NL);
		field[i][ft_strlen(field[i]) - 1] = '\0';
	}
	if (len > (size_t)INT_MAX / i)
		return (MAP_TOO_BIG);
	return (NULL);
}

static void	count_cep(char c, int *cnt_c, int *cnt_e, int *cnt_p)
{
	if (c == 'C')
		++(*cnt_c);
	else if (c == 'E')
		++(*cnt_e);
	else if (c == 'P')
		++(*cnt_p);
}

static char	*check_count_cep(int cnt_c, int cnt_e, int cnt_p)
{
	if (!cnt_c)
		return (MAP_NO_COLLECTIBLE);
	else if (!cnt_e)
		return (MAP_NO_EXIT);
	else if (cnt_p != 1)
		return (MAP_INVALID_POS);
	return (NULL);
}

char	*check_elem_of_map(char **field)
{
	int		cnt_c;
	int		cnt_e;
	int		cnt_p;
	int		i;
	int		j;

	cnt_c = 0;
	cnt_e = 0;
	cnt_p = 0;
	i = -1;
	while (field[++i] != NULL)
	{
		j = -1;
		while (field[i][++j])
		{
			if (ft_strchr("01CEP", field[i][j]) == NULL)
				return (MAP_UNKNOWN_CHAR);
			if ((!i || field[i + 1] == NULL || !j || !field[i][j + 1])
				&& field[i][j] != '1')
				return (MAP_INVALID_WALL);
			count_cep(field[i][j], &cnt_c, &cnt_e, &cnt_p);
		}
	}
	return (check_count_cep(cnt_c, cnt_e, cnt_p));
}
