/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:26:18 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/16 15:26:35 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int const	g_comb[24][4] = {
{1, 2, 3, 4},
{1, 2, 4, 3},
{1, 3, 2, 4},
{1, 3, 4, 2},
{1, 4, 2, 3},
{1, 4, 3, 2},
{2, 1, 3, 4},
{2, 1, 4, 3},
{2, 3, 1, 4},
{2, 3, 4, 1},
{2, 4, 1, 3},
{2, 4, 3, 1},
{3, 1, 2, 4},
{3, 1, 4, 2},
{3, 2, 1, 4},
{3, 2, 4, 1},
{3, 4, 1, 2},
{3, 4, 2, 1},
{4, 1, 2, 3},
{4, 1, 3, 2},
{4, 2, 1, 3},
{4, 2, 3, 1},
{4, 3, 1, 2},
{4, 3, 2, 1}
};

int	verify_tab(int **tab, int *arg);

void	linecpy(int *dest, const int src[4])
{
	int	i;

	i = -1;
	while (++i < 4)
		dest[i] = src[i];
}

int	bruteforce(int **tab, int *arg)
{
	int	i;

	i = 0;
	while (i < 331776)
	{
		linecpy(tab[0], g_comb[i / 13824]);
		linecpy(tab[1], g_comb[i / 576 % 24]);
		linecpy(tab[2], g_comb[i / 24 % 24]);
		linecpy(tab[3], g_comb[i % 24]);
		if (verify_tab(tab, arg) == 0)
			return (0);
		i++;
	}
	return (1);
}
