/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/07/10 19:42:54 by sosokin          ###   ########.fr       */
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
		printf("COMMAND - %s\nARGS - ", com->command);
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
		printf("OUTPUT REDIRECTIONS:\n");
		out_redir = com->redir_out;
		while (out_redir)
		{
			redir = (t_redir  *)(out_redir->content);
			printf("PATH - %s, IS_ADD_MODE - %d\n", redir->path, redir->mode);
			out_redir = out_redir->next;
		}
		commands = commands->next;
	}
}

int	execute(char *line, t_envp *envp_var)
{
	t_list	*commands;
	char	**args;
	int		exit_code;

	exit_code = NOTFOUND;
	lexer(line, envp_var);
	commands = get_commands(envp_var);
	//print_cmd_debug(commands);
	if (ft_lstsize(commands) == 1)
	{
		args = get_args((t_cmd *)(commands->content));
		exit_code = builtin_exec(args, 0, envp_var);
		free(args);
	}
	if (exit_code == NOTFOUND)
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
		printf("%s %d\n", __FILE__, __LINE__);
	while (*args)
	{
		printf("%s %d\n", __FILE__, __LINE__);
		exit_code = execute(*args, envp_var);
		if (exit_code == 255)
			break;
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

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_envp	*envp_var;
	int		exit_code;
	int		last_code;

	last_code = 0;
	envp_var = NULL;
	ft_singals();
	envp_init(envp, &envp_var);
	if (argc > 1 && !ft_strcmp(argv[1], "-c"))
		last_code = run_from_args(argv[2], envp_var);
	else
	{
		while (get_line(envp_var, &line))
		{
			add_history(line);
			exit_code = execute(line, envp_var);
			free(line);
			if (exit_code == 255)
				break;
			last_code = exit_code;
		}
		printf("exit\n");
	}
	 if(envp_var->envp_list && &(envp_var->envp_list))
	 	ft_lstclear(&(envp_var->envp_list), &free);
	if(envp_var->token_list && &(envp_var->token_list))
	 	ft_lstclear(&envp_var->token_list, &free_token);
	if (envp_var && &(envp_var))
		free(envp_var);
	//TODO почистить лики от лексера:w
	system("leaks minishell");
	return (last_code);
}
