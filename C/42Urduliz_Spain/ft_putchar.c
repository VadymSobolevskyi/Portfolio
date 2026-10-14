/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:20:18 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/23 15:20:24 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a function that prints one character to STDOUT.
*/

#include <unistd.h>

char	ft_putchar(char x)
{
	write(0, &x, 1);
}
