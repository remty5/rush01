/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:09:30 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 15:49:49 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	**complete_tab(int **tab, int *arg)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (arg[i] == 4 && arg[i + 4] == 1)
			ft_fullfill_column(tab, i, arg[i]);
		if (arg[i] == 1 && arg[i + 4] == 4)
			ft_fullfill_column(tab, i, arg[i]);
		i++;
	}
	return (tab);
}
