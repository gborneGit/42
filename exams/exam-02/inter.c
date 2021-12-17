#include <unistd.h>

int	is_doublon(char *str, int i)
{
	char	c;

	c = str[i];
	while (i--)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	is_in_set(char *set, char c)
{
	if (!set)
		return (0);
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1] && av[1][i])
	{
		if (is_in_set(av[2], av[1][i]) && !is_doublon(av[1], i))
			write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}