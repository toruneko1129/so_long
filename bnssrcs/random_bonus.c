/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:54:48 by hkawakit          #+#    #+#             */
/*   Updated: 2021/09/19 21:55:06 by hkawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

unsigned int	ft_rand(void)
{
	static unsigned int	x = 123456789;
	static unsigned int	y = 362436069;
	static unsigned int	z = 521288629;
	static unsigned int	w = 88675123;
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
	int		cnt;

	cnt = (int)(ft_rand() % 100);
	if (seed <= 0)
		return ;
	seed %= SEED_MAX;
	while (cnt--)
		ft_rand();
	ft_seed(seed - 1);
}
