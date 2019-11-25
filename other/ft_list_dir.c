#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	DIR		*dp;
	struct dirent	*ret;

	if (ac != 2)
		return (0);
	dp = opendir(av[1]);
	if (dp != NULL)
	{
		while (ret = readdir(dp))
		{
			if ((ret->d_name)[0] != '.')
				printf("%s\n",ret->d_name);
		}
	}
	if(closedir(dp) == -1)
		printf("Error in closedir");
	return (0);
}
