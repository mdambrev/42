/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 14:53:44 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/08 15:39:42 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	fork_bin(t_clist *param)
{
	pid_t pid;

	pid = fork();
	if(pid == 0)
		exec_bin(param);
	else 
	{
		wait(NULL);
	}
}

void  bin_bin(t_clist *param)
{
	if(CONTENT(1) == 1 && CONTENT(2) == 0)
	{
		fork_bin(param);
	}
}
