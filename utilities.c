/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:32:25 by jbuan             #+#    #+#             */
/*   Updated: 2021/09/27 10:37:44 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	free_everything(char *stock1, char *stock2, char **stock)
{
	int	i;

	i = 0;
	if (ft_strlen(stock1) > 0)
		free(stock1);
	if (ft_strlen(stock2) > 0)
		free(stock2);
	if (stock)
	{	
		i = 0;
		while (stock[i])
		{
			if (ft_strlen(stock[i]) > 0)
				free(stock[i]);
			i++;
		}
		free(stock);
	}
	return (0);
}

char	*error_sentences(char **stock)
{
	struct s_list	s;

	s.i = 0;
	s.j = 0;
	s.k = 0;
	s.bash = "-bash: : command not found\n";
	s.error = malloc(ft_strlen(s.bash) + ft_strlen(stock[0]) + 2);
	while (s.j < ft_strlen(s.bash) + ft_strlen(s.error))
	{
		if (s.bash[s.j] == ':' && s.bash[s.j + 1] == ' '
			&& s.bash[s.j + 2] == 'c')
		{
			while (stock[0][s.k])
			{
				s.error[s.i] = stock[0][s.k];
				s.i++;
				s.k++;
			}
		}
		s.error[s.i] = s.bash[s.j];
		s.i++;
		s.j++;
	}
	s.error[s.i] = '\0';
	return (s.error);
}
