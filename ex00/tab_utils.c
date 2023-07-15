/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:27:01 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/15 15:58:19 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	create_tab(int ***tab, int size)
{
	int	i;

	*tab = malloc(size * sizeof(int *));
	if (*tab == NULL)
		return (1);
	i = 0;
	while (i < size)
	{
		(*tab)[i] = malloc(size * sizeof(int));
		if ((*tab)[i++] == NULL)
			return (1);
	}
	return (0);
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
