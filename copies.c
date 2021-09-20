#include "pipex.h"

char	*copy_file1_to_stock1(int argc, char *argv[], char *stock1)
{
	int	i;

	i = 0;
	while(argv[(argc - argc) + 1][i])
	{
		stock1[i] = argv[1][i];
		i++;
	} 
	stock1[i] = '\0';
	return (0);
}

char	*copy_file2_to_stock2(int argc, char *argv[], char	*stock2)
{
	int	i;

	i = 0;
	while(argv[argc - 1][i])
	{
		stock2[i] = argv[argc - 1][i];
		i++;
	}
	stock2[i] = '\0';
	return (0);
}

char	*copies(int i, char *argv[], char **stock)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	l = 0;
	while (argv[i][j])
	{
		if (argv[i][j] == ' ')
		{
			l++;
			j++;
			k = 0;
		}	
		stock[l][k] = argv[i][j];
		j++;
		k++;
	}
	stock[l + 1] =  NULL;
	return (0);
}

char	*modify_copy(int i, char *modif, char *stock[])
{
	int		j;
	int		k;
	char	*path;
	
	malloc_modify_copy(i, &path, &modif, stock);
	k = 0;
	j = 0;
	while (k < (ft_strlen(path) + ft_strlen(stock[i])))
	{
		if (k < (ft_strlen(path)))
		{
			modif[k] = path[k];
			k++;
		}	
		else
		{
			modif[k] = stock[i][j];
			j++;
			k++;
		}
	}
	modif[k] = '\0';
	return (modif);
}
