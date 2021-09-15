/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 00:37:45 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 21:31:28 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(const char *filename)
{
	int		fd;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror_exit(filename);
	return (fd);
}

t_list	*read_map(int fd)
{
	t_list	*lst;
	char	*str;
	t_list	*new;

	lst = NULL;
	while (ft_lstsize(lst) < INT_MAX - 1)
	{
		errno = 0;
		str = get_next_line(fd);
		new = NULL;
		if (str != NULL)
			new = ft_lstnew(str);
		if (errno)
		{
			free(str);
			ft_lstclear(&lst, free);
			close(fd);
			strerror_exit(errno);
		}
		else if (str == NULL)
			break ;
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}

void	close_map(const char *filename, int fd, t_list **lst)
{
	errno = 0;
	if (close(fd) == -1)
	{
		ft_lstclear(lst, free);
		perror_exit(filename);
	}
}

char	**conv_list_to_2darray(t_list **lst)
{
	char		**field;
	int			i;
	t_list		*res;
	const int	size = ft_lstsize(*lst);

	errno = 0;
	field = (char **)malloc(((size_t)size + 1) * sizeof(char *));
	if (field == NULL)
	{
		ft_lstclear(lst, free);
		strerror_exit(errno);
	}
	field[size] = NULL;
	i = -1;
	res = *lst;
	while (++i < size)
	{
		field[i] = res->content;
		res = res->next;
	}
	return (field);
}
