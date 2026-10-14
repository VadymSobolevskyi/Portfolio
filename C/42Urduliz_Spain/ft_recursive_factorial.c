/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:54:29 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/22 18:54:37 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a recursive function that returns the factorial of the number given as a
parameter.
• If there’s an error, the function should return 0.
*/

int	ft_recursive_factorial(int nb)
{
	if ((nb == 1) || (nb == 0))
		return (1);
	else if ((nb <= 2147483647) && (nb >= 0))
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("result: %d\n", ft_recursive_factorial(3));
	printf("result: %d\n", ft_recursive_factorial(5));
}
*/
