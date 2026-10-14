/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:31:46 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/22 19:31:55 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Reproduce the behavior of the function strlen (man strlen).
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
