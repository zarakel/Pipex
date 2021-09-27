/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:24:24 by jbuan             #+#    #+#             */
/*   Updated: 2021/09/27 11:00:45 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(char *stock1, char **stock, int *fd2)
{
	struct s_list	s;

	s.modif = NULL;
	close(s.fd[1]);
	close(fd2[0]);
	s.fd[0] = open(stock1, O_RDWR, 0644);
	dup2(fd2[1], STDOUT_FILENO);
	dup2(s.fd[0], STDIN_FILENO);
	s.modif = modify_copy(0, s.modif, stock);
	command_not_found(s.modif, stock, &s.error);
	execve(s.modif, stock, NULL);
	free(s.modif);
	close(s.fd[0]);
	close(fd2[1]);
	return (0);
}
