/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:10:22 by jbuan             #+#    #+#             */
/*   Updated: 2021/09/27 10:17:14 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*malloc_files(int argc, char *argv[], char **stock1, char **stock2)
{
	*stock1 = (char *)malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
	*stock2 = (char *)malloc(sizeof(char) * ft_strlen(argv[argc - 1]) + 1);
	return (0);
}

char	**malloc_tab(int argc, char *argv[], char ***stock)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[argc][i])
	{
		if (argv[argc][i] == ' ')
			j++;
		i++;
	}
	*stock = (char **)malloc(sizeof(char *) * j + 2);
	return (0);
}

char	*malloc_strings(int argc, char *argv[], char **stock)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (argv[argc][i])
	{
		if (argv[argc][i] == ' ')
		{
			i++;
			stock[j] = (char *)malloc(sizeof(char) * k);
			k = 0;
			j++;
		}
		i++;
		k++;
	}
	stock[j] = (char *)malloc(sizeof(char) * k);
	stock[j + 1] = (char *)malloc(sizeof(char) * 1);
	return (0);
}

char	*malloc_modify_copy(int i, char **path, char **modif, char *stock[])
{
	int		j;
	char	*s1[34];

	fill_string_cmd(s1);
	j = 0;
	while (s1[j])
	{
		if (ft_strcmp(stock[i], s1[j]) == 1)
		{
			*path = "/bin/";
			break ;
		}
		j++;
		if (s1[j] == '\0')
			*path = "/usr/bin/";
	}
	if (ft_strlen(*path) == 5 || ft_strlen(*path) == 9)
		*modif = malloc(ft_strlen(stock[i]) + ft_strlen(*path) + 1);
	return (0);
}
