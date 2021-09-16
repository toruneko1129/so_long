#include "so_long.h"

static void	image_init(t_image *image, void *mlx, char *path)
{
	image->img = mlx_xpm_file_to_image(mlx, path, &(image->w), &(image->h));
	image->path = path;
}

static void	put_image(t_data *data, int x, int y, char type)
{
	void	*img;

	if (type == '0')
		img = data->space.img;
	else if (type == '1')
		img = data->wall.img;
	else if (type == 'C')
		img = data->collectible.img;
	else if (type == 'E')
		img = data->exit.img;
	else
		img = data->player.img;
	mlx_put_image_to_window(data->mlx, data->win, img, IMG_SIZE * x,
		       	IMG_SIZE * y);
	if (type == 'P')
	{
		data->pos_player.x = x;
		data->pos_player.y = y;
	}
}

void	data_init(t_data *data)
{
	int		i;
	int		j;

	data->h = 0;
	while ((data->field)[data->h] != NULL)
		++(data->h);
	data->w = ft_strlen((data->field)[0]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, IMG_SIZE * data->w, 
			IMG_SIZE * data->h, "so_long");
	image_init(&(data->space), data->mlx, IMG_SPACE);
	image_init(&(data->wall), data->mlx, IMG_WALL);
	image_init(&(data->collectible), data->mlx, IMG_COLLECTIBLE);
	image_init(&(data->exit), data->mlx, IMG_EXIT);
	image_init(&(data->player), data->mlx, IMG_PLAYER);
	i = -1;
	while (++i < data->w)
	{
		j = -1;
		while (++j < data->h)
			put_image(data, i, j, (data->field)[j][i]);
	}
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 33, 1L << 17, free_data, data);
	mlx_loop(data->mlx);
}

int		free_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->space.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->collectible.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	free_2darray(data->field);
	return (0);
}
