#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void	errexit(void)
{
	write(STDERR_FILENO, "echo: write: Failed.\n", 21);
	exit(1);
}

void	ft_flag(char *argv, int *flags)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i] == 'n')
			*flags |= 1;
		else if (argv[i] == 'E')
		{
			if (*flags & 2)
				*flags ^= 2;
		}
		else if (argv[i] == 'e')
			*flags |= 2;
		else
			break;
	}
}

int	main(int argc, char *argv[])
{
	int	flags;

	flags = 0;
	while (*++argv && *argv[0] == '-')
		ft_flag(*argv, &flags);
	if (flags & 2)
		write(1, "\t", 1);
	while (*argv)
	{
		if (write(STDOUT_FILENO, *argv, strlen(*argv)) == -1)
			errexit();
		if (*++argv)
			write(1, " ", 1);
	}
	if (!(flags & 1))
		write(1, "\n", 1);
	return (0);
}
