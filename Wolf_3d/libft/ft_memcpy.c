/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:28:25 by mdambrev          #+#    #+#             */
/*   Updated: 2015/01/24 17:40:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned	int	x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)dest)[x] = ((unsigned char*)src)[x];
		x++;
	}
	return (dest);
}
