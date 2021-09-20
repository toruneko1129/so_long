/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:08:03 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 21:53:58 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define CONTINUE 0
# define FINISH 1
# define LOSE 2
# define TRUE 1
# define FALSE 0

//file descriptor
# define STDIN 0
# define STDOUT 1
# define STDERR 2

//seed
# ifndef SEED
#  define SEED 42
#  define RANDOM_MOVE_RATE 20
# endif
# define SEED_MAX 100000

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
# define IMG_ENEMY1 "imgs/enemy1.xpm"
# define IMG_ENEMY2 "imgs/enemy2.xpm"
# define IMG_ENEMY3 "imgs/enemy3.xpm"
# define IMG_ENEMY4 "imgs/enemy4.xpm"
# define IMG_ENEMY5 "imgs/enemy5.xpm"
# define IMG_ENEMY6 "imgs/enemy6.xpm"
# define IMG_ENEMY7 "imgs/enemy7.xpm"
# define IMG_ENEMY8 "imgs/enemy8.xpm"
# define IMG_NUM_OF_COLLECTIBLE 2
# define IMG_NUM_OF_EXIT 2
# define IMG_NUM_OF_PLAYER 8
# define IMG_NUM_OF_ENEMY 8
# define SWITCH_INTERVAL 10000
# define MOVE_ENEMY 100000

//keys
# define ESCAPE 0xff1b
# define W 0x0077
# define A 0x0061
# define S 0x0073
# define D 0x0064

//message
# define CLEAR "You cleared this stage!!!"
# define GAMEOVER "GAME OVER You are killed by enemy..."
# define MSG_SIZE 50

//error message
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
	int		cnt_s;
	int		is_exit_player;
	int		sprite;
	int		player_dir;
	int		enemy_dir;
	char	*msg;
	void	*mlx;
	void	*win;
	t_tex	tex;
	t_image	space;
	t_image	wall;
	t_image	collectible[IMG_NUM_OF_COLLECTIBLE];
	t_image	exit[IMG_NUM_OF_EXIT];
	t_image	player[IMG_NUM_OF_PLAYER];
	t_image	enemy[IMG_NUM_OF_ENEMY];
	t_grid	pos_player;
	t_grid	pos_enemy;
}	t_data;

//load_map_bonus.c
int				open_map(const char *filename);
t_list			*read_map(int fd);
void			close_map(const char *filename, int fd, t_list **lst);
char			**conv_list_to_2darray(t_list **lst);

//parse_map_bonus.c
char			*check_shape_of_map(char **field);
char			*check_elem_of_map(char **field);

//random_bonus.c
unsigned int	ft_rand(void);
void			ft_seed(int seed);

//data_init_bonus.c
void			get_mapinfo(t_data *data);
void			setup_mlx(t_data *data);
void			load_image_from_xpm(t_image *image, void *mlx, char *path);
void			load_images(t_data *data);
void			reg_hooks(t_data *data);

//load_image_utils_bonus.c
int				load_collectible(t_data *data);
int				load_exit(t_data *data);
int				load_player(t_data *data);
int				load_enemy(t_data *data);

//draw_bonus.c
int				draw_tex(t_data *data);

//hook_bonus.c
int				key_hook(int keycode, t_data *data);
int				loop_hook(t_data *data);

//move_bonus.c
int				move_player(int keycode, t_data *data);
int				move_enemy(t_data *data);

//free_exit_bonus.c
void			free_data_error(t_data *data);
int				free_data_exit(t_data *data);

//error_bonus.c
void			puts_errormsg_exit(char *s);
void			perror_exit(const char *s);
void			strerror_exit(int errnum);
void			data_error_exit(t_data *data, char *s);

//utils_bonus.c
void			get_2darray_size(t_data *data);
void			free_2darray(char **arr);
t_image			get_image_from_char(t_data data, char c);
char			*get_msg_from_keycode(int keycode);
void			gen_enemy(t_data *data);

#endif
