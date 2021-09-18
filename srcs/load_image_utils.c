#include "so_long.h"

int	load_collectible(t_data *data)
{
	const char	*path[2] = 
			{IMG_COLLECTIBLE1,
			IMG_COLLECTIBLE2};
	int			i;

	i = -1;
	while (++i < 2)
	{
		load_image_from_xpm(&((data->collectible)[i]), data->mlx,
				(char *)path[i]);
		if (data->collectible[i].tex.img == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}
