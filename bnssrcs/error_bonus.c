/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:55:41 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 16:48:37 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puts_errormsg_exit(char *s)
{
	ft_putendl_fd(ERROR, STDERR);
	ft_putendl_fd(s, STDERR);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *s)
{
	ft_putendl_fd(ERROR, STDERR);
	perror(s);
	exit(EXIT_FAILURE);
}

void	strerror_exit(int errnum)
{
	ft_putendl_fd(ERROR, STDERR);
	ft_putendl_fd(strerror(errnum), STDERR);
	exit(EXIT_FAILURE);
}

void	data_error_exit(t_data *data, char *s)
{
	free_data_error(data);
	puts_errormsg_exit(s);
}
