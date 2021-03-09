#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(const char *str);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);

#endif