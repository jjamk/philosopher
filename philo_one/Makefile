CC = gcc
NAME = philo_one
HEADER = includes
UTILS = utils
SRCS = philo_one.c input_arg.c init.c is.c $(UTILS)/ft_atoi.c\
$(UTILS)/ft_putnbr_fd.c $(UTILS)/is_number.c $(UTILS)/ft_putstr.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER) -pthread -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -pthread -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(OBJS)

re : fclean all