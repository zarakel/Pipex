int	parent_process(char *stock2, char **stock, int *fd2)
{
	struct s_list s;

	s.modif = NULL;
	wait (NULL);
	close(s.fd[0]);
	close(fd2[1]);
	if ((s.fd[1] = open(stock2, O_TRUNC | O_RDWR, 0644)) == -1)
		s.fd[1] = open("file2", O_CREAT | O_RDWR, 0644);
	dup2(s.fd[1], STDOUT_FILENO);
	dup2(fd2[0], STDIN_FILENO);
	s.modif = modify_copy(0, s.modif, stock);
	command_not_found(s.modif, stock, &s.error);
	execve(s.modif, stock, NULL);
	free(s.modif);
	close(s.fd[1]);
	close(fd2[0]);
	return 0;
}