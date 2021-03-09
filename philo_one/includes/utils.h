/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:50:11 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 16:50:13 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		is_number(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *str);

#endif
