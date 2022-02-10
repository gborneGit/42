#include "libft.h"

void	print_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		ft_printf("%s\n", strs[i++]);
}

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char	**copy_strs(char **strs)
{
	char	**new;
	int		i;

	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	strs_len(char **strs)
{
	int	i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**strs_append(char **strs, const char *str)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (strs_len(strs) + 2));
	if (!new)
		return (NULL);
	if (!strs)
	{
		new[0] = ft_strdup(str);
		if (!new[0])
			return (NULL);
		new[1] = NULL;
		return (new);
	}
	i = 0;
	while (strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	free_strs(strs);
	return (new);
}

char	**strs_join(char **strs1, char **strs2)
{
	int		i;
	int		j;
	char	**new;

	new = malloc(sizeof(char *) * (strs_len(strs1) + strs_len(strs2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (strs1 && strs1[i])
	{
		new[i] = ft_strdup(strs1[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	j = 0;
	while (strs2 && strs2[j])
	{
		new[i + j] = ft_strdup(strs2[j]);
		if (!new[i + j])
			return (NULL);
		j++;
	}
	new[i + j] = NULL;
	free_strs(strs1);
	free_strs(strs2);
	return (new);
}