/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:21:39 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 13:50:02 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_params(char *str)
{
	int	i;
	int	count_nb;
	int	count_space;

	i = 0;
	count_nb = 0;
	count_space;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			count_nb++;
		if (str[i] == ' ')
			count_space++;
		i++;
	}
	if (count_nb != 16)
		return (1);
	else if (count_space != 15)
		return (1);
	else
		return (0);
}

int	*convert_params(char *str, int *tab_arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= 30)
	{
		tab_arg[i] = str[i] - '0';
		i++;
		j += 2;
	}
	return (tab_arg);
}

int	ft_check_numbers(int *tab_arg)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		
		j = i + 4;
		if (((tab_arg[i] + tab_arg[j]) >= 3) && ((tab_arg[i] + tab_arg[j]) <= 5))
			i++;
		else
			return (1);
	}
	i += 4;
	while (i <= 11)
	{
		j = i + 4;
		if (((tab_arg[i] + tab_arg[j]) >= 3) && ((tab_arg[i] + tab_arg[j]) <= 5))
			i++;
		else
			return (1);
	}
	return (0);
}
