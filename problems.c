#include "pipex.h"

void	ft_exit(char *stock)
{
	if (access(stock, F_OK) == -1)
	{
		perror("");
		exit(-1);
	}
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