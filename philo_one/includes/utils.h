#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		is_number(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *str);

#endif