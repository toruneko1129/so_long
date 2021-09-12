/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:02:16 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 01:44:11 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_args(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
		puts_errormsg_exit(INVALID_ARGS);
	ext = ft_strrchr(argv[1], '.');
	if (ext == NULL)
		puts_errormsg_exit(INVALID_ARGS);
	if (ft_strncmp(".ber", ext, 5))
		puts_errormsg_exit(INVALID_ARGS);
}

static void	load_map(const char *filename)
{
	int		fd;
	t_list	*lst;

	fd = open_map(filename);
	lst = read_map(fd);
	//ft_lstclear(&lst, free);
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	load_map(argv[1]);
	return (0);
}
