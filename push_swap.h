/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/01/13 15:50:40 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include ".libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

void	fill_stack(t_stack **stack, int value);
void	print_stack(t_stack *stack);

#endif
