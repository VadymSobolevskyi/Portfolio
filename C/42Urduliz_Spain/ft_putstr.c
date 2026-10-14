/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:21:16 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/22 19:21:21 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a function that displays a string of characters on the standard output.
*/

char	ft_putchar(char x);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
/*
int	main()
{
	ft_putstr("abcd");
	ft_putstr("\n");
	ft_putstr("");
	ft_putstr("\n");
	return (0);
}
*/
