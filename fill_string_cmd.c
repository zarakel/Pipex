/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_string_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:13 by jbuan             #+#    #+#             */
/*   Updated: 2021/09/27 10:10:08 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fill_string_cmd_part1(char *s[34])
{
	s[0] = "dd";
	s[1] = "ksh";
	s[2] = "pax";
	s[3] = "stty";
	s[4] = "bash";
	s[5] = "df";
	s[6] = "launchctl";
	s[7] = "ps";
	s[8] = "sync";
	s[9] = "cat";
	s[10] = "echo";
	s[11] = "link";
	s[12] = "pwd";
	s[13] = "tcsh";
	s[14] = "chmod";
	s[15] = "ed";
	s[16] = "ln";
	fill_string_cmd_part2(s);
}

void	fill_string_cmd_part2(char *s[34])
{
	s[17] = "rm";
	s[18] = "cp";
	s[19] = "expr";
	s[20] = "ls";
	s[21] = "rmdir";
	s[22] = "unlink";
	s[23] = "csh";
	s[24] = "hostname";
	s[25] = "mkdir";
	s[26] = "sh";
	s[27] = "wait4path";
	s[28] = "date";
	s[29] = "kill";
	s[30] = "mv";
	s[31] = "sleep";
	s[32] = "zsh";
	s[33] = NULL;
}

char	**fill_string_cmd(char *s[34])
{
	fill_string_cmd_part1(s);
	return (s);
}
