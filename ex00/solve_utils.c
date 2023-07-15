/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:15:36 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/15 19:44:00 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	visible(int **tab, int n)
{
	int	h;
	int	i;
	int	m;
	int	v;

	h = n / 8;
	i = n % 8 / 4 * 3;
	m = 0;
	v = 0;
	while (0 <= i && i <= 3)
	{
		if (m < tab[n % 4 * h + i * !h][n % 4 * !h + i * h])
		{
			m = tab[n % 4 * h + i * !h][n % 4 * !h + i * h];
			v++;
		}
		i -= n % 8 / 4 * 2 - 1;
	}
	return (v);
}

int	sum(int **tab, int n)
{
	int	h;
	int	i;
	int	s;

	h = n / 8;
	i = n % 8 / 4 * 3;
	s = 0;
	while (0 <= i && i <= 3)
	{
		s += tab[n % 4 * h + i * !h][n % 4 * !h + i * h];
		i -= n % 8 / 4 * 2 - 1;
	}
	return (s);
}

int	verify_tab(int **tab, int *arg)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("running with i: %d\n", i);
		printf("expected: %d ", arg[i]);
		printf("actual: %d ", visible(tab, i));
		printf("sum: %d\n", sum(tab, i));
		i++;
	}
	return (0);
}
