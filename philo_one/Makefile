# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 16:49:28 by skang             #+#    #+#              #
#    Updated: 2021/03/09 16:49:34 by skang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
