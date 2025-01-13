/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/13 15:51:20 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_printf("Error");
	return (1);
}

int	main(int ac, char **av)
{
	size_t	i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (error());
	while (++i < (size_t)ac)
	{
		if (!ft_atoi(av[i]))
			return (error());
		fill_stack(&stack_a, ft_atoi(av[i]));
	}
	ft_printf("Stack A\n");
	print_stack(stack_a);
	ft_printf("\nStack B\n");
	print_stack(stack_b);
	return (0);
}
