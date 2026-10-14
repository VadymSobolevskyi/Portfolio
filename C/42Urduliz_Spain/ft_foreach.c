/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:33:14 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/24 14:33:19 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create the function ft_foreach which, for a given ints array, applies a function on
all elements of the array. This function will be applied following the array’s order.
• Here’s how the function should be prototyped :
void ft_foreach(int *tab, int length, void (*f)(int));
• For example, the function ft_foreach could be called as follows in order to display
all ints of the array :
ft_foreach(tab, 1337, &ft_putnbr);
*/

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, "\n", 1);
}
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
int	main(void)
{
	int	l;
	int	arr[3]={2, 3, 4};
	int	*ptr = arr;

	ft_foreach(ptr, 3, &ft_putchar);
	return (0);
}
*/
