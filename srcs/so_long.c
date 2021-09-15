/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:02:16 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 21:40:16 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_args(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
		puts_errormsg_exit(INVALID_ARGS);
	ext = ft_strrchr(argv[1], '.');
	if (ext == NULL || ft_strncmp(".ber", ext, 5))
		puts_errormsg_exit(INVALID_ARGS);
}

static char	**load_map(const char *filename)
{
	int		fd;
	t_list	*lst;
	char	**field;

	fd = open_map(filename);
	lst = read_map(fd);
	close_map(filename, fd, &lst);
	field = conv_list_to_2darray(&lst);
	ft_lstclear(&lst, NULL);
	return (field);
}

static void	parse_map(char **field)
{
	char	*msg;

	msg = check_shape_of_map(field);
	if (msg == NULL)
		msg = check_elem_of_map(field);
	if (msg != NULL)
	{
		free_2darray(field);
		puts_errormsg_exit(msg);
	}
}

int	main(int argc, char **argv)
{
	char	**field;

	check_args(argc, argv);
	field = load_map(argv[1]);
	parse_map(field);
	free_2darray(field);
	return (0);
}
