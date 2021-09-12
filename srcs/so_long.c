/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:02:16 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/12 23:47:00 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_args(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
		puts_error_exit(INVALID_ARGS);
	ext = ft_strrchr(argv[1], '.');
	if (ext == NULL)
		puts_error_exit(INVALID_ARGS);
	if (ft_strncmp(".ber", ext, 5))
		puts_error_exit(INVALID_ARGS);
}

static void	check_file(const char *filename)
{
	int		fd;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || errno)
		strerror_exit();
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	check_file(argv[1]);
	return (0);
}
