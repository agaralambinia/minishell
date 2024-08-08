/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:43:35 by sosokin           #+#    #+#             */
/*   Updated: 2024/08/08 21:47:56 by sosokin          ###   ########.fr       */
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
	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		if (ft_strncmp(lim, line, ft_strlen(lim) + 1) == 0)
			break ;
		line[ft_strlen(line)] = '\n';
		write(fd, line, ft_strlen(line));
		line = get_next_line(0);
	}
	close(fd);
	return (1);
}

void	redir_in(t_cmd *cmd)
{
	char	*file;
	int		cmd_ind;
	int		fd;
	t_list	*tmp;
	t_r		*cur;

	tmp = cmd->redir_in;
	while (tmp)
	{
		cur = (t_r *)(tmp->dt);
		file = cur->path;
		if (cur->m)
		{
			cmd_ind = run_heredoc(file);
			check_for_exit(NULL, cur->path, cmd_ind < 0);
			file = "here_doc";
		}
		fd = open(file, O_RDONLY);
		check_for_exit(NULL, cur->path, fd < 0);
		dup2(fd, 0);
		close(fd);
		tmp = tmp->next;
	}
}
