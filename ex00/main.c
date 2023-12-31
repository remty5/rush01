/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:14:34 by almarico          #+#    #+#             */
/*   Updated: 2023/07/16 20:03:37 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_check_params(char *str);
int		*convert_params(char *str, int *tab_arg);
int		ft_check_numbers(int *tab_arg);
int		ft_check_face_equ(int *tab_arg);
int		ft_check_face_sum(int *tab_arg);
int		create_tab(int ***tab, int size);
int		free_tab(int **tab, int size);
int		bruteforce(int **tab, int *arg);
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
	if (ft_check_face_equ(*tab_arg) != 0)
		return (1);
	if (ft_check_face_sum(*tab_arg) != 0)
		return (1);
	return (0);
}

int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	error_free(int *arg)
{
	free(arg);
	return (error());
}

int	main(int argc, char **argv)
{
	int	**tab;
	int	*arg;

	if (argc != 2)
		return (error());
	else if (sanitize_params(&arg, argv) != 0)
		return (error_free(arg));
	else if (create_tab(&tab, 4) != 0)
		return (error_free(arg));
	else if (bruteforce(tab, arg) != 0)
		return (error_free(arg) + free_tab(tab, 4));
	else
	{
		free(arg);
		display_tab(tab, 4);
		free_tab(tab, 4);
		return (0);
	}
}
