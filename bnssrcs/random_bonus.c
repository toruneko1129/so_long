#include "so_long_bonus.h"

unsigned int	ft_rand(void)
{
	static unsigned int x = 123456789;
	static unsigned int y = 362436069;
	static unsigned int z = 521288629;
	static unsigned int w = 88675123;
	unsigned int		t;

	t = x ^ (x << 11);
	x = y;
	y = z;
	z = w;
	w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	return (w);
}

void	ft_seed(int seed)
{
	if (seed < 0)
		return ;
	seed %= SEED_MAX;
	while (seed--)
		ft_rand();
}
