/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/12 20:12:27 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	execute(char **line, t_envp *envp_var)
{
	t_list	*commands;
	t_list	*token_list;
	int		exit_code;
	int		lex_res;

	token_list = NULL;
	lex_res = lexer(line, &token_list, envp_var);
	if (!lex_res)
		return (258);
	else if (lex_res == INT_MAX)
		return (0);
	commands = get_commands(token_list, envp_var);
	if (&(token_list) && token_list)
		ft_lstclear(&token_list, &free_token);
	if (ft_lstsize(commands) == 1)
		exit_code = run_single(commands, envp_var);
	else
		exit_code = run_command(commands, envp_var);
	if (exit_code == 130)
		envp_var->hide_prompt = true;
	if (commands && &(commands))
		ft_lstclear(&commands, &free_cmd);
	return (exit_code);
}

char	*get_line(t_envp *envp_var, char **line)
{
	if (envp_var->hide_prompt)
	{
		printf("\n");
		envp_var->hide_prompt = false;
	}
	*line = readline("minishell:minishel_user$ ");
	return (*line);
}

static int	handle_input(char **line, t_envp *envp_var)
{
	int		exit_code;

	exit_code = execute(line, envp_var);
	add_history(*line);
	free(*line);
	if (envp_var->is_exit)
		return (0);
	envp_var->last_code = exit_code;
	return (1);
}

int	run_from_args(char *arg, t_envp *envp_var)
{
	char	**args;
	int		exit_code;
	int		last_code;
	char	**tmp;

	args = ft_split(arg, ';');
	tmp = args;
	last_code = 0;
	while (*args)
	{
		exit_code = execute(args, envp_var);
		if (exit_code == 255)
			break ;
		last_code = exit_code;
		args++;
	}
	free_arr((void *)tmp);
	return (last_code);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_envp	*envp_var;
	int		exit_code;

	envp_var = NULL;
	ft_singals();
	envp_init(envp, &envp_var);
	envp_var->last_code = 0;
	if (argc > 1 && !ft_strcmp(argv[1], "-c"))
		envp_var->last_code = run_from_args(argv[2], envp_var);
	else
	{
		while (get_line(envp_var, &line))
		{
			if (!handle_input(&line, envp_var))
				break ;
		}
	}
	printf("exit\n");
	exit_code = envp_var->last_code;
	free_envp(envp_var);
	system("leaks minishell");
	return (exit_code);
}
