#include "so_long.h"

static void	my_mlx_pixel_put(t_tex *tex, int x, int y, int color)
{
	char	*dst;

	dst = tex->addr + (y * tex->line + x * (tex->bits / 8));
	*(unsigned int *)dst = color;
}

static unsigned int my_mlx_pixel_get_color(t_tex tex, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = tex.addr + (y * tex.line + x * (tex.bits / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static void	draw_image(t_tex *tex, t_image image, int y, int x)
{
	int				i;
	int				j;
	unsigned int	color;

	i = -1;
	while (++i < image.h)
	{
		j = -1;
		while (++j < image.w)
		{
			color = my_mlx_pixel_get_color(image.tex, j, i);
			my_mlx_pixel_put(tex, IMG_SIZE * x + j, IMG_SIZE * y + i, color);
		}
	}
}

static void	draw_map(t_data *data, t_tex *tex)
{
	int		i;
	int		j;
	t_image	image;

	i = -1;
	while (++i < data->h)
	{
		j = -1;
		while (++j < data->w)
		{
			image = get_image_from_char(*data, (data->field)[i][j]);
			draw_image(tex, image, i, j);
		}
	}
}

void	draw_tex(t_data *data)
{
	t_tex	tex;

	tex.img = mlx_new_image(data->mlx, IMG_SIZE * data->w,
		IMG_SIZE * data->h);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits, &tex.line, &tex.endian);
	//debug
	draw_map(data, &tex);
	mlx_put_image_to_window(data->mlx, data->win, tex.img, 0, 0);
	if (data->tex.img != NULL)
		mlx_destroy_image(data->mlx, data->tex.img);
	data->tex = tex;
}