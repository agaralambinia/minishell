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

int	execute(char *line, t_envp *envp_var)
{
	t_list	*commands;
	int		exit_code;

	if (!lexer(line, envp_var))
		return (258);
	commands = get_commands(envp_var);
//	print_lexer_debug(envp_var);
//	print_cmd_debug(commands);
	if (ft_lstsize(commands) == 1)
		exit_code = run_single(commands, envp_var);
	else
		exit_code = run_command(commands, envp_var);
	if (commands && &(commands))
		ft_lstclear(&commands, &free_cmd);
	return (exit_code);
}

int run_from_args(char *arg, t_envp *envp_var)
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
		exit_code = execute(*args, envp_var);
		if (exit_code == 255)
			break ;
		last_code = exit_code;
		args++;
	}
	free_arr((void *)tmp);
	return (last_code);
}

char	*get_line(t_envp *envp_var, char **line)
{
	char	*prompt;

	prompt = prompt_msg(envp_var);
	*line = readline(prompt);
	free(prompt);
	return (*line);
}

void free_envp(t_envp *envp_var)
{
	if (envp_var->envp_list && &(envp_var->envp_list))
		ft_lstclear(&(envp_var->envp_list), &free);
	if (envp_var->token_list && &(envp_var->token_list))
		ft_lstclear(&envp_var->token_list, &free_token);
	if (envp_var && &(envp_var))
		free(envp_var);
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
			add_history(line);
			exit_code = execute(line, envp_var);
			free(line);
			if (envp_var->is_exit)
				break ;
			envp_var->last_code = exit_code;
		}
	}
	exit_code = envp_var->last_code;
	free_envp(envp_var);
	system("leaks minishell");
	return (exit_code);
}
