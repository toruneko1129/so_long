/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:08:03 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/17 23:23:33 by hkawakit         ###   ########.fr       */
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

//status
# define SUCCESS 0
# define FAILED 1

//file descriptor
# define STDIN 0
# define STDOUT 1
# define STDERR 2

//images
# define IMG_SIZE 64
# define IMG_SPACE "imgs/space.xpm"
# define IMG_WALL "imgs/wall.xpm"
# define IMG_COLLECTIBLE1 "imgs/collectible1.xpm"
# define IMG_COLLECTIBLE2 "imgs/collectible2.xpm"
# define IMG_EXIT1 "imgs/exit1.xpm"
# define IMG_EXIT2 "imgs/exit2.xpm"
# define IMG_PLAYER1 "imgs/player1.xpm"
# define IMG_PLAYER2 "imgs/player2.xpm"
# define IMG_PLAYER3 "imgs/player3.xpm"
# define IMG_PLAYER4 "imgs/player4.xpm"
# define IMG_PLAYER5 "imgs/player5.xpm"
# define IMG_PLAYER6 "imgs/player6.xpm"
# define IMG_PLAYER7 "imgs/player7.xpm"
# define IMG_PLAYER8 "imgs/player8.xpm"
# define SWITCH_INTERVAL 10000

//keys
# define ESCAPE 0xff1b

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

//structs
typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_tex;

typedef struct s_image
{
	t_tex	tex;
	char	*path;
	int		w;
	int		h;
}	t_image;

typedef struct s_grid
{
	int		x;
	int		y;
}	t_grid;

typedef struct s_data
{
	char	**field;
	int		w;
	int		h;
	int		cnt_c;
	int		is_exit;
	int		sprite;
	int		player_dir;
	void	*mlx;
	void	*win;
	t_tex	tex;
	t_image	space;
	t_image	wall;
	t_image	collectible[2];
	t_image	exit[2];
	t_image	player[8];
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
void	count_collectible(t_data *data);
void	setup_mlx(t_data *data);
void	load_image_from_xpm(t_image *image, void *mlx, char *path);
void	load_images(t_data *data);
void	reg_hooks(t_data *data);

//load_image_utils.c
int		load_collectible(t_data *data);
int		load_exit(t_data *data);
int		load_player(t_data *data);

//draw.c
int		draw_tex(t_data *data);

//hook.c
int		key_hook(int keycode, t_data *data);
int		loop_hook(t_data *data);

//free_exit.c
void	free_data_error(t_data *data);
int		free_data_exit(t_data *data);

//error.c
void	puts_errormsg_exit(char *s);
void	perror_exit(const char *s);
void	strerror_exit(int errnum);
void	data_error_exit(t_data *data, char *s);

//utils.c
void	get_2darray_size(t_data *data);
void	free_2darray(char **arr);
t_image	get_image_from_char(t_data data, char c);

#endif
