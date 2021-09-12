/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 00:37:45 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 01:45:12 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(const char *filename)
{
	int		fd;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || errno)
		perror_exit(filename);
	return (fd);
}

t_list	*read_map(int fd)
{
	t_list	*lst;
	char	*str;
	t_list	*new;

	errno = 0;
	lst = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (errno)
			strerror_exit(errno);
		else if (str == NULL)
			break ;
		new = ft_lstnew(str);
		if (errno)
			strerror_exit(errno);
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}
