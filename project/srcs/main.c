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

//TODO удалить перед защитой
void	print_lexer_debug(t_envp *envp_var)
{
	t_list	*iter; //TODO убрать - для дебага
	t_tn *t; //TODO убрать - для дебага

	iter = (t_list *)safe_malloc(sizeof(t_list));
	iter = envp_var->token_list;
	t = (t_tn *)safe_malloc(sizeof(t_tn));
	while (iter != NULL)
	{
		t = iter->dt;
		printf(PINK"%i TYPE [%s]\n"RESET, t->t_tp, t->data);
		iter = iter -> next;
	}
}

int	execute(char *line, t_envp *envp_var)
{
	t_list	*commands;
	int		exit_code;
	int		lex_res;

	lex_res = lexer(line, envp_var);
	print_lexer_debug(envp_var); //TODO удалить перед защитой
	if (!lex_res)
		return (258);
	else if (lex_res == INT_MAX)
		return (0);
	commands = get_commands(envp_var);
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
	char	*prompt;

	prompt = prompt_msg(envp_var);
	if (envp_var->hide_prompt)
	{
		printf("\n");
		envp_var->hide_prompt = false;
	}
	*line = readline(prompt);
	free(prompt);
	return (*line);
}

static int	handle_input(char *line, t_envp *envp_var)
{
	int		exit_code;

	add_history(line);
	exit_code = execute(line, envp_var);
	free(line);
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
		exit_code = execute(*args, envp_var);
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
			if (!handle_input(line, envp_var))
				break ;
		}
	}
	if (!(envp_var->is_exit))
		printf("exit\n");
	exit_code = envp_var->last_code;
	free_envp(envp_var);
	return (exit_code);
}
