#include "../includes/utils.h"

static int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	        ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);	
}