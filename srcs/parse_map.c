/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:55:58 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 20:13:41 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_shape_of_map(char **field)
{
	size_t	len;
	int		i;

	if (field[0] == NULL || ft_strlen(field[0]) == 1)
	{
		free_2darray(field);
		puts_errormsg_exit(EMPTY_MAP);
	}
	len = ft_strlen(field[0]);
	i = -1;
	while (field[++i] != NULL)
	{
		if (ft_strlen(field[i]) != len) 
		{
			free_2darray(field);
			puts_errormsg_exit(INVALID_SHAPE);
		}
		if (field[i][ft_strlen(field[i]) - 1] != '\n')
		{
			free_2darray(field);
			puts_errormsg_exit(MISS_NL);
		}
	}
}
