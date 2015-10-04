/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 17:50:53 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/04 17:34:23 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdio.h>

int					main(int argc, char **argv, char **env)
{
	t_clist *param;
	char **tab;
	int x;
	(void)argc;
	(void)argv;

	x = 0;
	param = init_param();
	tab = read_standar(param);
	dup_env(env, param);
	ret_bin(param);
//	printf("ret = %s\n", PARAM(3));
	execve(PARAM(3), tab, NULL);
	return (0);
}
