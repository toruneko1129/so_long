/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:55:41 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 01:20:12 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
