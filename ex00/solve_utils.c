/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:15:36 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/16 15:57:38 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible(int **tab, int n)
{
	int	h;
	int	i;
	int	max;
	int	vis;

	h = n / 8;
	i = n / 4 % 2 * 3;
	max = 0;
	vis = 0;
	while (0 <= i && i <= 3)
	{
		if (max < tab[n % 4 * h + i * !h][n % 4 * !h + i * h])
		{
			max = tab[n % 4 * h + i * !h][n % 4 * !h + i * h];
			vis++;
		}
		if (n / 4 % 2)
			i--;
		else
			i++;
	}
	return (vis);
}

int	sum(int **tab, int n)
{
	int	h;
	int	i;
	int	s;

	h = n / 8;
	i = 0;
	s = 0;
	while (i <= 3)
	{
		s += tab[n % 4 * h + i * !h][n % 4 * !h + i * h];
		i++;
	}
	return (s);
}

int	verify_tab(int **tab, int *arg)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i / 4 % 2 == 0 && sum(tab, i) != 10)
			return (1);
		if (visible(tab, i) != arg[i])
			return (1);
		i++;
	}
	return (0);
}
