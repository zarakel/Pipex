/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problems.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:30:44 by jbuan             #+#    #+#             */
/*   Updated: 2021/09/27 10:47:20 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *stock)
{
	if (access(stock, F_OK) == -1)
	{
		perror("");
		exit(-1);
	}
	return ;
}

char	*command_not_found(char *modif, char **stock, char **error)
{
	if (access(modif, F_OK) == -1)
	{
		*error = error_sentences(stock);
		write(2, *error, ft_strlen(*error));
	}
	return (0);
}
