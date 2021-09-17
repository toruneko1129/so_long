#include "so_long.h"

void	free_data(t_data *data)
{
	if (data->mlx != NULL && data->space.img != NULL)
		mlx_destroy_image(data->mlx, data->space.img);
	if (data->mlx != NULL && data->wall.img != NULL)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->mlx != NULL && data->collectible.img != NULL)
		mlx_destroy_image(data->mlx, data->collectible.img);
	if (data->mlx != NULL && data->exit.img != NULL)
		mlx_destroy_image(data->mlx, data->exit.img);
	if (data->mlx != NULL && data->player.img != NULL)
		mlx_destroy_image(data->mlx, data->player.img);
	if (data->mlx != NULL && data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	free_2darray(data->field);
}

int	free_data_exit(t_data *data)
{
	//mlx_destroy_image(data->mlx, data->space.img);
	//mlx_destroy_image(data->mlx, data->wall.img);
	//mlx_destroy_image(data->mlx, data->collectible.img);
	//mlx_destroy_image(data->mlx, data->exit.img);
	//mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->tex.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	free_2darray(data->field);
	exit(EXIT_SUCCESS);
	return (0);
}
