/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:21:39 by almarico          #+#    #+#             */
/*   Updated: 2023/07/15 23:27:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_params(char *str)
{
	int	i;
	int	count_nb;
	int	count_space;

	i = 0;
	count_nb = 0;
	count_space = 0;
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
		tab_arg[i] = str[j] - '0';
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
		if (((tab_arg[i] + tab_arg[j]) >= 3)
			&& ((tab_arg[i] + tab_arg[j]) <= 5))
			i++;
		else
			return (1);
	}
	i += 4;
	while (i <= 11)
	{
		j = i + 4;
		if (((tab_arg[i] + tab_arg[j]) >= 3)
			&& ((tab_arg[i] + tab_arg[j]) <= 5))
			i++;
		else
			return (1);
	}
	return (0);
}
/*
il y a des erreurs a gerer en plus, si je mt que des 2 em parametres
ca devrait retourner une erreurs alors que la ca ne le fais pas ,
j'ai essayer 2 fonctions, elles sont surement complementaires,
mais dans tout les cas l'erreur n'est pas detecter...
   */
int	ft_check_face(int *tab_arg)
{
	printf("coucou\n");
	if (tab_arg[0] == tab_arg[1] == tab_arg[2] == tab_arg[3])
		return (1);
	else if (tab_arg[4] == tab_arg[5] == tab_arg[6] == tab_arg[7])
		return (1);
	else if (tab_arg[8] == tab_arg[9] == tab_arg[10] == tab_arg[11])
		return (1);
	else if (tab_arg[12] == tab_arg[13] == tab_arg[14] == tab_arg[15])
		return (1);
	else
		return (0);
}
/*
int	ft_check_face(int *tab_arg)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i <= 3)
		res += tab_arg[i++];
	if (!(res >= 7 && res <= 10))
		return (1);
	res = 0;
	while (i <= 7)
		res += tab_arg[i++];
	if (!(res >= 7 && res <= 10))
		return (1);
	res = 0;
	while (i <= 11)
		res += tab_arg[i++];
	if (!(res >= 7 && res <= 10))
		return (1);
	res = 0;
	while (i <= 15)
		res += tab_arg[i++];
	if (!(res >= 7 && res <= 10))
		return (1);
	return (0);
}
*/
