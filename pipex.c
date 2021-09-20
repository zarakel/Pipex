#include "pipex.h"

int	pipex(int argc, char *argv[])
{
	struct s_list s;

	malloc_files(argc, argv, &s.stock1, &s.stock2);
	copy_file1_to_stock1(argc, argv, s.stock1);
	copy_file2_to_stock2(argc, argv, s.stock2);
	ft_exit(s.stock1);
	pipe(s.fd2);
	s.id = fork();
	if (s.id == 0 && s.stock1)
	{
		malloc_tab(2, argv, &s.stock);
		malloc_strings(2, argv, s.stock);
		copies(2, argv, s.stock);
		child_process(s.stock1, s.stock, s.fd2);
	}
	else if (s.id != 0 && s.stock2)
	{
		malloc_tab(3, argv, &s.stock);
		malloc_strings(3, argv, s.stock);
		copies(3, argv, s.stock);
		parent_process(s.stock2, s.stock, s.fd2);
	}
	free_everything(s.stock1, s.stock2, s.stock);
	return (0);
}