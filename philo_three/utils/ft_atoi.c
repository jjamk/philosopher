/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:52:57 by skang             #+#    #+#             */
/*   Updated: 2021/03/09 16:52:59 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_atoi(const char *str)
{
	int flag;
	int num;

	flag = 0;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' \
			|| *str == '\r' || *str == ' ')
		str++;
	if (*str != '+' && *str != '-' && *str < '0' && *str > '9')
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (flag)
		return (-num);
	return (num);
}
