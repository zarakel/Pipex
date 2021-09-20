#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list s;

struct s_list
{
	int		c;
	int		i;
	int		j;
	int		k;
	int		id;
	int		fd[2];
	int		fd2[2];
	char	*stock1;
	char	*stock2;
	char	*modif;
	char	**stock;
	char	*command_list_bin;
	char	*command_list_usr_bin;
	char	*bash;
	char	*error;
};

int		pipex(int argc, char *argv[]);
int		bonus(int argc, char *argv[]);
int		child_process(char *stock1, char *argv1[], int *fd2);
int		parent_process(char *stock2, char *argv1[], int *fd2);
char	*copy_file1_to_stock1(int argc, char *argv[], char *stock1);
char	*copy_file2_to_stock2(int argc, char *argv[], char *stock2);
char	*copies(int argc, char *argv[], char **stock);
char	*modify_copy(int i, char *modif, char **stock);
char	*malloc_files(int argc, char *argv[],char **stock1, char **stock2);
char	**malloc_tab(int argc, char* argv[], char ***stock);
char	*malloc_strings(int argc, char* argv[], char **stock);
char	*malloc_modify_copy(int i, char **path, char **modif, char *stock[]);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
int		free_everything(char *stock1, char *stock2, char **stock);
char	*error_sentences(char **stock);
char	*command_not_found(char *modif, char **stock, char **error);
void	ft_exit(char *stock1);
void	fill_string_cmd_part1(char *s[]);
void	fill_string_cmd_part2(char *s[]);
char	**fill_string_cmd(char *s[]);
int		main(int argc, char *argv[]);

#endif
