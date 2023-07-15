/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:27:01 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/15 11:43:46 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	**create_table(int size)
{
	int	**tab;
	int	i;

	tab = malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
		tab[i++] = malloc(size * sizeof(int));
	return (tab);
}

void	display_tab(int **tab, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = '0' + tab[i][j];
			write(1, &c, 1);
			if (++j < size)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	**tab;

	if (argc == 2)
	{
		tab = create_table(atoi(argv[1]));
		display_tab(tab, atoi(argv[1]));
	}
}
