#include "../include/minishell.h"

int	ft_chrcnt(char *ptr, char needle)
{
	int	i;

	i = 0;
	while (*ptr)
	{
		if (*ptr == needle)
			i++;
		ptr++;
	}
	return (i);
}
