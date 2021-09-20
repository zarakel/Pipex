#include "pipex.h"

int	bonus(int argc, char *argv[])
{
	struct s_list s;

	malloc_files(argc, argv, &s.stock1, &s.stock2);
	copy_file1_to_stock1(argc, argv, s.stock1);
	copy_file2_to_stock2(argc, argv, s.stock2);
	ft_exit(s.stock1);
	pipe(s.fd2);
	s.c = 2;
	s.id = fork();
		if (s.id == 0)
		{
			while(s.c < argc - 1)
			{
				malloc_tab(s.c, argv, &s.stock);
				malloc_strings(s.c, argv, s.stock);
				copies(s.c, argv, s.stock);
				child_process(s.stock1, s.stock, s.fd2);
				free_everything(s.stock1, s.stock2, s.stock);
				s.c++;
			}
		}
		else if (s.id != 0)
		{
			while (s.c + 1 < argc - 1)
			{
				malloc_tab(s.c + 1, argv, &s.stock);
				malloc_strings(s.c + 1, argv, s.stock);
				copies(s.c + 1, argv, s.stock);
				parent_process(s.stock2, s.stock, s.fd2);
				free_everything(s.stock1, s.stock2, s.stock);
				s.c++;
			}
		}
	return (0);
}