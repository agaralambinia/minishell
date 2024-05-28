/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/05/25 19:04:34 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	//(void)envp; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argc; //TODO - чтобы компилилось с флагами, убрать позже
	(void)argv; //TODO - чтобы компилилось с флагами, убрать позже
	g_envp_init(envp);
	line = readline(prompt_msg());
	while (line)
	{
		add_history(line);
		printf("You type %s, great...\n", line);
		if (lexer(line)) //TODO
			ft_exit_error("Lexer error\n"); //TODO выход с зачисткой
		line = readline(prompt_msg());
	}
	return (0);
}
