/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:02:28 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/22 18:02:49 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a function that displays the alphabet in lowercase, on a single line, by
ascending order, starting from the letter ’a’.
*/

char	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	x;

	x = 'a';
	while (x <= 'z')
	{
		ft_putchar(x);
		x++;
	}
}
/*
int	main(void)
{
	ft_print_alphabet();
}
*/
