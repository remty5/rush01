/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:09:30 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 19:29:14 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	**complete_other(int **tab, int *arg);
int	verify_tab(int **tab, int *arg);
int	error(void);

int	**ft_fullfill_column(int **tab, int i, int value)
{
	int	j;
	int	number;

	j = 0;
	if (value == 4)
	{
		number = 1;
		while (j <= 4 && number <= 4)
			tab[j++][i] = number++;
	}
	if (value == 1)
	{
		number = 4;
		while (j <= 4 && number >= 1)
			tab[j++][i] = number--;
	}
	return (tab);
}

int	**ft_fullfill_line(int **tab, int i, int value)
{
	int	j;
	int	number;

	i %= 8;
	j = 0;
	if (value == 4)
	{
		number = 1;
		while (j <= 4 && number <= 4)
			tab[i][j++] = number++;
	}
	if (value == 1)
	{
		number = 4;
		while (j <= 4 && number >= 1)
			tab[i][j++] = number--;
	}
	return (tab);
}

int	**complete_simple(int **tab, int *arg)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (arg[i] == 4 && arg[i + 4] == 1)
			ft_fullfill_column(tab, i, arg[i]);
		if (arg[i] == 1 && arg[i + 4] == 4)
			ft_fullfill_column(tab, i, arg[i]);
		if (arg[i] == 1 && arg[i + 4] != 4)
			tab[0][i] = 4;
		i++;
	}
	i += 4;
	while (i <= 11)
	{
		if (arg[i] == 4 && arg[i + 4] == 1)
			ft_fullfill_line(tab, i, arg[i]);
		if (arg[i] == 1 && arg[i + 4] == 4)
			ft_fullfill_line(tab, i, arg[i]);
		if (arg[i] == 1 && arg[i + 4] != 4)
			tab[i % 4][0] = 4;
		i++;
	}
	return (tab);
}

//complete_other(tab, arg);
int	complete_tab(int **tab, int *arg)
{
	complete_simple(tab, arg);
	if (verify_tab(tab, arg) != 0)
		return (error());
	return (0);
}
