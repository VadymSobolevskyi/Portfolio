/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:53:56 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/23 15:53:59 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a program that displays its given arguments sorted by ascii order.
• It should display all arguments, except for argv[0].
• All arguments have to have their own line.
*/

#include <unistd.h>

char	ft_putchar(char x)
{
	write(0, &x, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return ((int)*s1 - (int)*s2);
		s1++;
		s2++;
	}
	return ((int)*s1 - (int)*s2);
}

void	sort_strings(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[i]) < 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*s;

	sort_strings(argc, argv);
	i = 1;
	while (i < argc)
	{
		s = argv[i];
		while (*s != '\0')
		{
			ft_putchar(*s);
			s++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
