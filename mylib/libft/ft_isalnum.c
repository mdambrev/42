/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:07:13 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:11:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int c)
{
	if ((c <= 122 && c >= 97) || (c <= 90 && c >= 65))
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
