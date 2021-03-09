#include "../includes/utils.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(const char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);	
}