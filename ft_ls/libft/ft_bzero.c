/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:45:41 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/04 05:07:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)s)[x] = '\0';
		x++;
	}
}
