/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:43:35 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/07 16:49:56 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	run_heredoc(char *lim)
{
	int		fd;
	char	*line;

	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);
	line = readline("heredoc> ");
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		if (ft_strncmp(lim, line, ft_strlen(lim) + 1) == 0)
			break ;
		line[ft_strlen(line)] = '\n';
		write(fd, line, ft_strlen(line));
		line = readline("heredoc> ");
	}
	close(fd);
	return (1);
}

void	redir_in(t_cmd *cmd)
{
	char	*file;
	int		cmd_ind;
	int		fd;

	if (cmd->input)
	{
		file = cmd->input;
		if (cmd->inmode)
		{
			cmd_ind = run_heredoc(file);
			//TODO заменить на корректный метод выхода 
			if (cmd_ind < 0)
			{
				perror(cmd->command);
				exit(1);
			}
			file = "here_doc";
		}
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			perror(cmd->command);
			exit(1);
		}
		dup2(fd, 0);
		close(fd);
	}
}
