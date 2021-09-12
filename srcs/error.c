/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:55:41 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/12 23:46:51 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puts_error_exit(char *s)
{
	ft_putendl_fd(ERROR, STDERR);
	ft_putendl_fd(s, STDERR);
	exit(EXIT_FAILURE);
}

void	strerror_exit(void)
{
	ft_putendl_fd(ERROR, STDERR);
	ft_putendl_fd(strerror(errno), STDERR);
	exit(EXIT_FAILURE);
}