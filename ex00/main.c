/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_attempts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:59:26 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 13:48:02 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_check_params(char *str);
int	*convert_params(char *str, int *tab_arg);
int	ft_chek_numbers(int *tab_arg);

int	main(int argc, char **argv)
{
	int	*tab_arg;
	argv++;
	argc--;
	if (argc != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ft_check_params(argv[0]) == 0)
	{
		tab_arg = (int)malloc(16 * sizeof(int));
		if (tab_arg == NULL)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		tab_arg = *convert_params(str, tab_arg);
		if (ft_check_numbers(tab_arg) != 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}
