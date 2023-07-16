/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:19:58 by almarico          #+#    #+#             */
/*   Updated: 2023/07/16 12:08:28 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_complete_comb(int **tab, int value, int arg_index)
{

	if (arg_index <= 3 && value == 3)
		tab[value - 1][arg_index] = 4;
	if (arg_index <= 7 && value == 3)
		tab[value - 1][arg_index % 4] = 4;
	if (arg_index <= 11 && value == 3)
		tab[value - 1][arg_index % 4] = 4;
	if (arg_index <= 15 && value == 3)
		tab[value - 1][arg_index % 4] = 4;
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
