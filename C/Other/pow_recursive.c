/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_recursive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vadym Sobolevskyi                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:34:58 by vs                 #+#    #+#            */
/*   Updated: 2026/09/24 15:35:03 by vs                 ###   #########       */
/*                                                                            */
/* ************************************************************************** */

// function Power (recursive) 

#include <stdio.h>

int pow(int a, int b)
{
    if (b==0) return (1);
    return (a*pow(a, b-1));
}
/*
void main()
{
    printf("\n Function pow\n");
    printf("pow (2, 3) = %d\n", pow(2, 3));
    printf("pow (2, 2) = %d\n", pow(2, 2));
    printf("pow (2, 1) = %d\n", pow(2, 1));
    printf("pow (2, 0) = %d\n", pow(2, 0));
}
*/
