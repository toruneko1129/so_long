#include "so_long.h"

int		key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		free_data(data);
		exit(0);
	}
	return (keycode);
}
