/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsobolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:48:44 by vsobolev          #+#    #+#             */
/*   Updated: 2026/09/23 19:48:49 by vsobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK
• Create a macro ABS which replaces its argument by it absolute value
*/

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) (((Value >> 31) | 1) * Value)

#endif
