/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:18:39 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/22 18:18:44 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered
as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’.
char	ft_putchar(char x);
*/

void	ft_is_negative(int n)
{
	char	c;

	c = 'P';
	if (n < 0)
	{
		c = 'N';
	}
	ft_putchar(c);
}
/*
int	main(void)
{
	ft_is_negative(-1);
}
*/
