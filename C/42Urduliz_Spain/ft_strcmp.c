/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:17:29 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/23 15:17:34 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Reproduce the behavior of the function strcmp (man strcmp).
*/

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
