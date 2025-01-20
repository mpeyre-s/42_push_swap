/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeyre-s <mpeyre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:18:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/20 14:16:36 by mpeyre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi_overflow(char *str)
{
	long	result;
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	result = result * sign;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return (result);
}
