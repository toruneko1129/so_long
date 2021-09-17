/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:08:03 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/13 22:43:11 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

//file descriptor
# define STDIN 0
# define STDOUT 1
# define STDERR 2

//images
# define IMG_SIZE 64
# define IMG_SPACE "imgs/space.xpm"
# define IMG_WALL "imgs/wall.xpm"
# define IMG_COLLECTIBLE "imgs/collectible1.xpm"
# define IMG_EXIT "imgs/exit1.xpm"
# define IMG_PLAYER "imgs/player1.xpm"

//keys
# define ESCAPE 65307

//message
# define ERROR "Error"
# define INVALID_ARGS "Usage: ./so_long maps/<mapname>.ber"
# define MAP_EMPTY "Map is empty."
# define MAP_INVALID_SHAPE "Map is not a rectangle."
# define MAP_MISS_NL "Map is missing a newline."
# define MAP_TOO_BIG "Map is too big."
# define MAP_UNKNOWN_CHAR "Map contains unknown characters."
# define MAP_INVALID_WALL "Map is not closed by walls."
# define MAP_NO_COLLECTIBLE "There's no collectible on the map."
# define MAP_NO_EXIT "There's no exit on the map."
# define MAP_INVALID_POS "There's no/multiple starting position on the map."
# define MALLOC_ERR "Cannot allocate memory"

typedef struct	s_tex
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_tex;

typedef struct	s_image
{
	void	*img;
	char	*path;
	int		w;
	int		h;
}	t_image;

typedef struct	s_grid
{
	int		x;
	int		y;
}	t_grid;

typedef struct	s_data
{
	char	**field;
	int		w;
	int		h;
	void	*mlx;
	void	*win;
	t_tex	tex;
	t_image	space;
	t_image	wall;
	t_image	collectible;
	t_image	exit;
	t_image	player;
	t_grid	pos_player;
}	t_data;

//load_map.c
int		open_map(const char *filename);
t_list	*read_map(int fd);
void	close_map(const char *filename, int fd, t_list **lst);
char	**conv_list_to_2darray(t_list **lst);

//parse_map.c
char	*check_shape_of_map(char **field);
char	*check_elem_of_map(char **field);

//data_init.c
void	 setup_mlx(t_data *data);

//hook.c
int		key_hook(int keycode, t_data *data);

//free_exit.c
void	free_data(t_data *data);
int		free_data_exit(t_data *data);

//error.c
void	puts_errormsg_exit(char *s);
void	perror_exit(const char *s);
void	strerror_exit(int errnum);
void	data_error_exit(t_data *data, char *s);

//utils.c
void	get_2darray_size(t_data *data);
void	free_2darray(char **arr);

#endif
