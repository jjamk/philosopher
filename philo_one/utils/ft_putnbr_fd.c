#include "../includes/utils.h"

void	ft_putnbr_fd(int n, int fd)
{
	long num;
	char a;

	num = n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		a = n + '0';
		write(fd, &a, sizeof(a));
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}
