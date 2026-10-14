/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:22:08 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/22 18:22:11 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a function that takes a pointer to int as a parameter, and sets the value "42"
to that int.
*/

/*
#include <stdio.h>
*/
void	ft_ft(int *nbr)
{
	*nbr = 42;
}
/*
int	main(void)
{
	int	number;

	number = 41;

	ft_ft(&number);

	printf("%d\n", number);

	return (0);
}
*/
