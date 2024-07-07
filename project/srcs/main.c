/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/07 19:55:17 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_lexer_debug(t_envp *envp_var)
{
	t_list	*iter; //TODO убрать - для дебага
	t_token *t; //TODO убрать - для дебага

	iter = (t_list *)safe_malloc(sizeof(t_list));
	iter = envp_var->token_list;
	t = (t_token *)safe_malloc(sizeof(t_token));
	while (iter != NULL)
	{
		t = iter->content;
		printf(PINK"%i TYPE [%s]\n"RESET, t->token_type, t->t_data);
		iter = iter -> next;
	}
}

void	print_cmd_debug(t_list	*commands)
{
	t_list	*args;
	t_list	*in_redir;
	t_list	*out_redir;
	t_redir *redir;

	printf("%s %d\n", __FILE__, __LINE__);
	while (commands)
	{
		t_cmd *com = (t_cmd *)(commands->content);
		//printf("COMMAND - %s\nARGS - ", com->command);
		args = com->args;
		while (args)
		{
			//printf("%s ", args->content); //TODO сереж тут компилятор ругается
			args = args->next;
		}
		printf("\nINPUT REDIRECTIONS:\n");
		in_redir = com->redir_in;
		while (in_redir)
		{
			redir = (t_redir  *)(in_redir->content);
			printf("PATH OR END - %s, IS_HEREDOC - %d\n", redir->path, redir->mode);
			in_redir = in_redir->next;
		}
		//printf("OUTPUT REDIRECTIONS:\n");
		out_redir = com->redir_out;
		while (out_redir)
		{
			redir = (t_redir  *)(out_redir->content);
			printf("PATH - %s, IS_ADD_MODE - %d\n", redir->path, redir->mode);
			out_redir = out_redir->next;
		}
		commands = commands->next;
	}
	printf("%s %d\n", __FILE__, __LINE__);
}

int	execute(char *line, t_envp *envp_var)
{
	t_list	*commands;
	char	**args;
	int		exit_code;

	lexer(line, envp_var);
	commands = get_commands(envp_var);
	if (ft_lstsize(commands) == 1)
	{
		args = get_args((t_cmd *)(commands->content));
		exit_code = builtin_exec(args, 0, envp_var);
		if (exit_code != ERROR)
			return (exit_code);
	}
	exit_code = run_command(commands, envp_var);
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_envp	*envp_var;
	t_list	*commands;
	int		exit_code;
	int		last_code;

	last_code = 0;
	envp_var = NULL;
	ft_singals();
	envp_init(envp, &envp_var);
	if (argc > 1 && !ft_strcmp(argv[1], "-c"))
		last_code = execute(argv[2], envp_var);
	else
	{
		line = readline(prompt_msg(envp_var));
		while (line)
		{
			add_history(line);
			exit_code = execute(line, envp_var);
			if (exit_code == 255)
				break;
			last_code = exit_code;
			line = readline(prompt_msg(envp_var));
		}
		printf("exit\n");
	}
	// if(envp_var->envp_list && &(envp_var->envp_list))
	// 	ft_lstclear(&(envp_var->envp_list), &free);
	if(envp_var->token_list && &(envp_var->token_list))
	 	ft_lstclear(&envp_var->token_list, &free);
	if (envp_var && &(envp_var))
		free(envp_var);
	ft_lstclear(&commands, &free_cmd);
	//TODO почистить лики от лексера:w
//	system("leaks minishell");
	return (last_code);
}
