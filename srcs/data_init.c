#include "so_long.h"

void	 setup_mlx(t_data *data)
{
	get_2darray_size(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		data_error_exit(data, MALLOC_ERR);
	data->win = mlx_new_window(data->mlx, IMG_SIZE * data->w, 
			IMG_SIZE * data->h, "so_long");
	if (data->win == NULL)
		data_error_exit(data, MALLOC_ERR);
	data->tex.img = mlx_new_image(data->mlx, IMG_SIZE * data->w, 
			IMG_SIZE * data->h);
	data->tex.addr = mlx_get_data_addr(data->tex.img, &data->tex.bits,
			&data->tex.line, &data->tex.endian);
	mlx_hook(data->win, 33, 1L << 17, free_data_exit, data);
	mlx_loop(data->mlx);
}
