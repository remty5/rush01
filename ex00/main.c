/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:14:34 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 16:05:04 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_check_params(char *str);
int		*convert_params(char *str, int *tab_arg);
int		ft_check_numbers(int *tab_arg);
int		create_tab(int ***tab, int size);
int		**complete_tab(int **tab, int *arg);
void	display_tab(int **tab, int size);

int	sanitize_params(int **tab_arg, char **params)
{
	if (ft_check_params(params[1]) != 0)
		return (1);
	*tab_arg = malloc(16 * sizeof(int));
	if (*tab_arg == NULL)
		return (1);
	*tab_arg = convert_params(params[1], *tab_arg);
	if (ft_check_numbers(*tab_arg) != 0)
		return (1);
	return (0);
}

int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int	**tab;
	int	*arg;

	if (argc != 2)
		return (error());
	if (sanitize_params(&arg, argv) != 0)
		return (error());
	if (create_tab(&tab, 4) != 0)
		return (error());
	complete_tab(tab, arg);
	display_tab(tab, 4);
	return (0);
}
