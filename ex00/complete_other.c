/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:19:58 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 22:35:41 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_complete_comb(int **tab, int value, int arg_index)
{
	int	i;
	int	number;

	i = 0;
	number = 1;
	if (arg_index <= 3)
	{
		while (value >= 1)
			tab[i++][arg_index] = 5 - value--;
		while (i <= 3)
			tab[i++][arg_index] = number++;
	}
	if (arg_index <= 11)
	{
		arg_index %= 4;
		while (value >= 1)
			tab[arg_index][i++] = 5 - value--;
		while (i <= 3)
			tab[arg_index][i++] = number++;
	}
	return (tab);
}

int	**complete_other(int **tab, int *arg)
{
	int	k;

	k = 0;
	while (k <= 3)
	{
		if (!(arg[k] == 4 || (arg[k] == 1 && arg[k + 4] == 4)))
			ft_complete_comb(tab, arg[k], k);
		k++;
	}
	k += 4;
	while (k <= 11)
	{
		if (!(arg[k] == 4 || (arg[k] == 1 && arg[k + 4] == 4)))
			ft_complete_comb(tab, arg[k], k);
		k++;
	}
	return (tab);
}
