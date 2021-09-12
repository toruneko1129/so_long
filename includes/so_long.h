/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:08:03 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 01:26:49 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERROR "Error"
# define INVALID_ARGS "Usage: ./so_long maps/<mapname>.ber"

int		open_map(const char *filename);
t_list	*read_map(int fd);
void	puts_errormsg_exit(char *s);
void	perror_exit(const char *s);
void	strerror_exit(int errnum);

#endif
