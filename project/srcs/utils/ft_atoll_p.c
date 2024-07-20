/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:36:52 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/20 20:37:02 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

long long	convert(const char *str, int *is_ov/*, int neg*/)
{
	long long	res;
	long long	prev;

	res = 0;
	prev = 0;
	while (ft_isdigit((int)*str))
	{
		prev = res;
		res = (res * 10) + *str - '0';
		if (prev > res /*&& !(res == LONG_LONG_Ma && neg == -1)*/)
		//if (prev > res && !(res == -2147483648 && neg == -1))
			*is_ov = 1;
		str++;
	}
	return (res);
}

long long	ft_atoll_p(const char *str, int *is_ov)
{
	char		neg;
	long long	res;

	neg = 1;
	while (*str)
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		else
			break ;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	res = convert(str, is_ov/*, neg*/);
	return (res * neg);
}
